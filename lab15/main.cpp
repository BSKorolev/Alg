#include <iostream>
#include <string>
#include <vector>
#include <stack>

struct Tree   
{
    int data;        
    Tree* left;      
    Tree* right;    
    Tree* parent;  
};

Tree* MAKE(int data, Tree* p)    
{
    Tree* q = new Tree;          
    q->data = data;
    q->left = nullptr;
    q->right = nullptr;
    q->parent = p;
    return q;
}

void ADD(int data, Tree*& root)      
{
    if (root == nullptr) 
    {         
        root = MAKE(data, nullptr);
        return;
    }
    Tree* v = root;
    while ((data < v->data && v->left != nullptr) || (data > v->data && v->right != nullptr))       
        if (data < v->data)
            v = v->left;
        else
            v = v->right;
    if (data == v->data)
        return;
    Tree* u = MAKE(data, v);
    if (data < v->data)
        v->left = u;
    else
        v->right = u;
}

void ADD_FICTIVE(int data, Tree*& root, bool is_left)        
{
    Tree* v = root;
    Tree* u = MAKE(data, v);
    if (is_left)
        v->left = u;
    else
        v->right = u;
}

void FILL(std::string& str, int& i, Tree*& root)       
{
    int value = 0;
    while (str[i] != '\0')
    {
        switch (str[i])                  
        {
        case '(':                     
        {
            i++;
            value = 0;
            while ((str[i] >= '0') && (str[i] <= '9'))   
            {
                value = value * 10 + str[i] - '0';
                i++;
            }

            if (value != 0)
            {
                ADD_FICTIVE(value, root, true);
                if (str[i] == '(')
                    FILL(str, i, root->left);
            }
            value = 0;
            break;
        }
        case ',':                        
        {
            i++;
            value = 0;
            while ((str[i] >= '0') && (str[i] <= '9'))
            {
                value = value * 10 + str[i] - '0';
                i++;
            }

            if (value != 0)
            {
                ADD_FICTIVE(value, root, false);
                if (str[i] == '(')
                    FILL(str, i, root->right);
            }
            value = 0;
            break;
        }

        case ')':
            i++;
            return;
        default:
            break;
        }
    }
}

void PASS(Tree* v)   
{
    if (v == nullptr)
        return;
    PASS(v->left);
    std::cout << v->data << std::endl;
    PASS(v->right);
}

Tree* SEARCH(int data, Tree* v)   
{
    if (v == nullptr)                
        return v;
    if (v->data == data)
        return v;
    if (data < v->data)
        return SEARCH(data, v->left);
    else
        return SEARCH(data, v->right);
}

void DELETE(int data, Tree*& root)   
{
    Tree* u = SEARCH(data, root);    
    if (u == nullptr)
        return;

    if (u->left == nullptr && u->right == nullptr && u == root)   
    {
        delete root;
        root = nullptr;
        return;
    }

    if (u->left == nullptr && u->right != nullptr && u == root)           
    {
        Tree* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }

    if (u->left != nullptr && u->right == nullptr && u == root)           
    {
        Tree* t = u->left;
        while (t->right != nullptr)
            t = t->right;
        u->data = t->data;
        u = t;
    }

    if (u->left != nullptr && u->right != nullptr)                
    {
        Tree* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }
    Tree* t;                     
    if (u->left == nullptr)
        t = u->right;
    else
        t = u->left;
    if (u->parent->left == u)
        u->parent->left = t;
    else
        u->parent->right = t;
    if (t != nullptr)
        t->parent = u->parent;
    delete u;
}

void CLEAR(Tree*& v)            
{
    if (v == nullptr)          
        return;
    CLEAR(v->left);
    CLEAR(v->right);
    delete v;
    v = nullptr;
}

void preorder(Tree* root)       
{
    if (root == nullptr)
        return;
    std::cout << root->data << std::endl;    
    preorder(root->left);     
    preorder(root->right);    
}

void inorder(Tree* root)      
{
    if (root == nullptr)                   
        return;
    inorder(root->left);                    
    std::cout << root->data << std::endl;    
    inorder(root->right);                  
}

void postorder(Tree* root)       

{
    if (root == nullptr) 
        return;
    postorder(root->left);    
    postorder(root->right);    
    std::cout << root->data << std::endl;  

}

void iterative_order(Tree* root)        
{
    std::stack<Tree*> stack;       
    stack.push(root);

    while (!stack.empty())    
    {
        Tree* node = stack.top();
        stack.pop();
        std::cout << node->data << std::endl;

        if (node->left != nullptr)
        {
            stack.push(node->left);
        }
        if (node->right != nullptr)
        {
            stack.push(node->right);
        }
    }
}


int main()
{
    setlocale(LC_ALL, "rus");
    std::string str;
    std::cout << "    !" << std::endl;
    std::cin >> str;

    Tree* root = nullptr;

    int value = 0, i = 0;
    while ((str[i] >= '0') && (str[i] <= '9'))     
    {
        value = value * 10 + str[i] - '0';
        i++;
    }
    ADD(value, root);
    FILL(str, i, root);

    PASS(root);

    std::cout << "========================" << std::endl;

    preorder(root);
    std::cout << "========================" << std::endl;
    inorder(root);
    std::cout << "========================" << std::endl;
    postorder(root);
    std::cout << "========================" << std::endl;
    iterative_order(root);
    std::cout << "========================" << std::endl;
    CLEAR(root);
    return 0;
}
