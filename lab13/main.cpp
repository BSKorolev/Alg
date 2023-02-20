//В начале программы создается объект таблицы хеширования HashTable. 
//Затем из файла input.txt считываются данные строкой за строкой. 
//Каждая строка вставляется в таблицу с помощью функции Insert. 
//Затем данные сохраняются в файл output.txt, используя функцию Get. После этого программа завершается.
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class HashNode 
{        
public:
    HashNode(int key, std::string data)
        :m_key(key), m_data(data)
    {}
    std::string data() 
    {
        return m_data;
    }
    int key() 
    {
        return m_key;
    }
private:
    int m_key;
    std::string m_data;
};

class HashTable
{
public:
    HashTable() 
    {
        for (int i = 0; i < start_size; i++) 
        {
            hash_table.push_back(HashNode(i, ""));
        }
    };

    int GetStartSize() 
    {
        return start_size;
    }

    int HashFunction(const std::string& str);
    void Insert(const std::string& node);
    std::string Get(const std::string& str);
    int size();

    HashNode operator[] (int key) 
    {         
        return hash_table[key];
    }

private:
    std::vector<HashNode> hash_table;
    int start_size = 12;
};

int HashTable::HashFunction(const std::string& str)
{  
    int hash = 0;
    for (auto i = 0; i < str.size(); i++) 
    {
        hash += (str[i] - '0');
    }
    return (hash / 23);
}

int HashTable::size() 
{         
    return hash_table.size();
};

std::string HashTable::Get(const std::string& str)   
{
    int key = HashFunction(str);
    if (hash_table.size() - 1 < key)
        key = GetStartSize();
    for (int i = key; i < hash_table.size(); i++) 
    {
        if (hash_table[i].data() == str) 
        {
            return hash_table[i].data();
        }
    }
    return "  !";
}


void HashTable::Insert(const std::string& node)    
{
    int key = HashFunction(node);
    if (key >= hash_table.size())
    {
        hash_table.push_back(HashNode(key, node));
    }
    else {
        int i = key;
        bool flag = false;
        while (hash_table[i].data() != "") 
        {
            i++;
        }
        if (hash_table.size() < i) 
        {
            hash_table.push_back(HashNode(key, node));
        }
        else {
            hash_table[i] = HashNode(key, node);
            return;
        }
    }
    return;
}


int main()
{
    HashTable table;
    std::string line;
    int n = 1;
    std::ifstream in("input.txt");
    std::ofstream out;
    if (in.is_open())
    {
        while (getline(in, line))  
        {
            table.Insert(line);
            std::cout << n << ") " << table.Get(line) << std::endl;
            n++;
        }
    }
    in.close();

    out.open("output.txt", std::ios::out | std::ios::trunc);  
    out << " | \n";
    int i = 0;
    for (; i < table.size() - 1; i++) 
    {
        out << table[i].key() << " - " << table[i].data() << "\n";
    }
    out << table[i].key() << " - " << table[i].data();
    out.close();
    return 0;
}
