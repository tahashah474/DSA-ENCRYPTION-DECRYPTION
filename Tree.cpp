#include<iostream>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};
class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = new Node;
        root->data = 'R';
        root->left = root->right = nullptr;
    }
    void tree_insertion(char x)
    {
        Node *ptr = new Node;
        ptr->data = x;
        ptr->left = nullptr;
        ptr->right = nullptr;

        Node *curr = root;
        Node *parent = nullptr;

        while (curr != nullptr)
        {
            parent = curr;
            if (x < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }

        if (x < parent->data)
            parent->left = ptr;
        else
            parent->right = ptr;
    }
    Node *getroot()
    {
        return root;
    }
};
