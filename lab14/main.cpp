#include <iostream>    
#include <string>
#include <list>
#include <algorithm>
#include <fstream>


class HashNode
{                      
public:
    HashNode(const std::string& data) :
        m_data(data)
    {}
    std::string data() const 
    {
        return m_data;
    }
private:
    std::string m_data;
};

bool operator==(const HashNode& left, const HashNode& right)
{   
    return left.data() == right.data();
}

size_t hash(const HashNode& id)
{                  
    if (id.data().length() == 1)
        return 2 * size_t(id.data()[0]);
    return size_t(id.data()[0]) + size_t(id.data()[1]);
}

class HashTable
{       
public:
    static const size_t min_value = int('A') + int('0');
    static const size_t max_value = int('z') + int('z');
    static const size_t size = max_value - min_value;

    void Insert(const HashNode& id)
    {                             
        m_hash_table[hash(id) - min_value].push_back(id);
    }

    HashNode& Get(const std::string& id_data) 
    {                       
        std::list<HashNode>& line = m_hash_table[hash(id_data) - min_value];
        std::list<HashNode>::iterator i = std::find(line.begin(), line.end(), id_data);
        return *i;
    }
private:
    std::list<HashNode> m_hash_table[size];
};


int main() 
{
    setlocale(LC_ALL, "Rus");
    HashTable table;
    std::string line;
    int n = 1;
    std::ifstream in("input.txt");
    if (in.is_open())
    {
        while (getline(in, line))                 
        {
            table.Insert(HashNode(line));
            std::cout << n << ") " << table.Get(line).data() << std::endl;
            n++;
        }
    }
    return 0;
}
