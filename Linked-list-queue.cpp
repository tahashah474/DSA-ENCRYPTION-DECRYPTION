#include <iostream>
using namespace std;
struct Linkedlist_Node
{
    char character;
    string binarycode;
    Linkedlist_Node *next;
};

class Linked_list
{
    Linkedlist_Node *front;
    Linkedlist_Node *rear;

public:
    Linked_list()
    {
        front = nullptr;
        rear = nullptr;
    }

    void insert_into_linkedlist(char n, string code)
    {
        Linkedlist_Node *newnode = new Linkedlist_Node;
        newnode->character = n;
        newnode->binarycode = code;
        newnode->next = nullptr;
        if (rear == nullptr)
        {
            front = newnode;
        }
        else
        {
            rear->next = newnode;
        }

        rear = newnode;
    }

    void display_char_code()
    {
        if (rear == nullptr)
        {
            cout << "Stacklist is empty" << endl;
        }
        else
        {
            Linkedlist_Node *temp = front;
            cout << "Char" << "\t|\t" << "Binary code "<<endl;
            while (temp != nullptr)
            {
                cout << temp->character << "\t|\t " << temp->binarycode;
                temp = temp->next;
                cout<<endl;
            }
        }
    }
    void display_code()
    {
        if (rear == nullptr)
        {
            cout << "Stacklist is empty" << endl;
        }
        else
        {
            Linkedlist_Node *temp = front;
            while (temp != nullptr)
            {
                cout <<temp->binarycode;
                temp = temp->next;
            }
            cout<<"..."<<endl;
        }
    }
};