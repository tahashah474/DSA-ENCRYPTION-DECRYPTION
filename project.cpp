#include <iostream>
#include "stack.cpp"
#include "circular-queue.cpp"
#include "Linked-list-queue.cpp"
#include "Tree.cpp"

using namespace std;

bool char_tobinary(Node *root, string &code, char target);
void msg_reverse(Stack &s, string message);
void shiftingright(Queue &q, Stack &s);
void Encoded_msg(BST &tree, Queue &q, Linked_list &list);
char decode_msg(BST &tree, string code);
void binary_to_char(BST &tree, Queue &q, Linked_list &list);
void shiftingleft(Queue &q, Stack &s);
void rereversemsg(Queue &q, Stack &s);
int main()
{
    srand(time(0));
    BST Tree;
    Queue q;
    q.front = -1;
    q.rear = -1;
    Stack s;
    s.top = -1;
    Linked_list list;
    string msg;

    cout << " Input Message : ";
    getline(cin, msg);

    cout << "\n Encrypting message..." << endl;
    cout << "After Reversing : ";
    msg_reverse(s, msg);
    cout << "Shifting words : ";
    shiftingright(q, s);
    cout << "Binary Encoded : ";
    Encoded_msg(Tree, q, list);
    list.display_code();
    cout << "\nEncrypted Message : ";
    list.display_code();

    cout << "\n Decrypting message..." << endl;
    cout << "Decoded To : ";
    binary_to_char(Tree, q, list);
    display_queue(q);
    cout << "Reverse Shifting : ";
    shiftingleft(q, s);
    display_queue(q);
    cout << "After Reversing : ";
    rereversemsg(q, s);
    stack_display(s);
    cout << "Final Output : ";
    stack_display(s);
    cout << "\n\nBinary code for Every Character" << endl;
    list.display_char_code();
    cout << "\nThe root character is : " << randomroot() << endl;
    return 0;
}

void msg_reverse(Stack &s, string message)
{

    for (int i = 0; i < message.length(); i++)
    {
        push_stack(s, message[i]);
    }
    reverse_stack(s);
}
void shiftingright(Queue &q, Stack &s)
{

    while (!stack_isempty(s))
    {
        insert_queue(q, pop_stack(s));
    }
    insert_queue(q, remove_queue(q));
    insert_queue(q, remove_queue(q));
    display_queue(q);
}

bool char_tobinary(Node *root, string &code, char target)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == target)
    {
        return true;
    }
    code.push_back('0');
    if (char_tobinary(root->left, code, target))
    {
        return true;
    }
    else
    {
        code.pop_back();
    }

    code.push_back('1');
    if (char_tobinary(root->right, code, target))
    {
        return true;
    }
    else
    {
        code.pop_back();
    }
    return false;
}
void Encoded_msg(BST &tree, Queue &q, Linked_list &list)
{
    Queue q2 = q;

    while (!queue_isempty(q))
    {
        tree.tree_insertion(remove_queue(q));
    }
    while (!queue_isempty(q2))
    {
        string code;
        char target = remove_queue(q2);
        char_tobinary(tree.getroot(), code, target);
        list.insert_into_linkedlist(target, code);
    }
}

char decode_msg(BST &tree, string code)
{
    Node *current = tree.getroot();
    for (int i = 0; i < code.length(); i++)
    {
        if (code[i] == '0')
        {
            current = current->left;
        }
        else if (code[i] == '1')
        {
            current = current->right;
        }
    }
    return current->data;
}
void binary_to_char(BST &tree, Queue &q, Linked_list &list)
{
    Linkedlist_Node *ptr = list.front;
    while (ptr != nullptr)
    {
        char ch = decode_msg(tree, ptr->binarycode);
        insert_queue(q, ch);
        ptr = ptr->next;
    }
}
void shiftingleft(Queue &q, Stack &s)
{
    int n = q.rear - q.front + 1;
    for (int i = 0; i < n - 2; i++)
    {
        insert_queue(q, remove_queue(q));
    }
}

void rereversemsg(Queue &q, Stack &s)
{
    while (!queue_isempty(q))
    {
        push_stack(s, remove_queue(q));
    }
    reverse_stack_with_ref(s);
}