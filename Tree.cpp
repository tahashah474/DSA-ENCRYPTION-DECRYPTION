#include <iostream>
using namespace std;

char randomroot()
{
    char c;
    int r = rand() % 52; // 52 letters total

    if (r < 26)
        c = 'A' + r; 
    else
        c = 'a' + (r - 26);//to be understood

    return c;
}
struct Node
{
    char data;
    Node *left;
    Node *right;
};
class BST
{
private://why private what happens if kept in publi
    Node *root;

public:
    BST()
    {
        root = new Node;
        root->data = randomroot();//placing the random new
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
