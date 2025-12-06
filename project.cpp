#include <iostream>
#include "stack.cpp"
#include "circular-queue.cpp"
#include "Tree.cpp"
#include "Linked-list-queue.cpp"

using namespace std;

bool generate_code(Node *root, string &code, char target);
void stack_encryption(Stack &s, string message);
void queue_shifting(Queue &q, Stack &s);
void Encoded_msg(BST &tree, Queue &q, Linked_list &list);
char decode_msg(BST &tree, string code);
void code_to_char(BST &tree, Queue &q, Linked_list &list);
void queue_reverse_shifting(Queue &q, Stack &s);
void reverse(Queue &q,Stack &s);
int main()
{
    BST Tree;
    Queue q;
    q.front = -1;
    q.rear = -1;
    Stack s;
    s.top = -1;
    Linked_list list;
    string msg;
    cout << "\t=============================================" << endl;
    cout << "\t|| WELCOME TO THE FSCOIETY ENCRYPTION TOOL ||" << endl;
    cout << "\t=============================================" << endl;
    cout << ":) Input Message : ";
    getline(cin, msg);

    cout << "\n Encrypting message..." << endl;
    cout << ":) [Stack] After Reversing : ";
    stack_encryption(s, msg);
    cout << ":) [Queue] After Shifting 2 times : ";
    queue_shifting(q, s);
    cout << ":) [Tree] Binary Encoded : ";
    Encoded_msg(Tree, q, list);
    list.display_code();
    cout << "\nEncrypted Message : ";
    list.display_code();
    
    
    cout << "\n Decrypting message..." << endl;
    cout << ":) [Tree] Decoded To : ";
    code_to_char(Tree, q, list);
    display_queue(q);
    cout << ":) [Queue] Reverse Shifting : ";
    queue_reverse_shifting(q, s);
    display_queue(q);
    cout << ":) [Stack] After Reversing : ";
    reverse(q,s);
    stack_display(s);
    cout << "\n\n========================================"<<endl;
    cout << "Final Output : ";
    stack_display(s);
    cout << "========================================";
    cout << "\n\nBinary code for Every Character" << endl;
    list.display_char_code();
    
    return 0;
}

void stack_encryption(Stack &s, string message)
{

    for (int i = 0; i < message.length(); i++)
    {
        push_stack(s, message[i]);
    }
    reverse_stack(s);
}
void queue_shifting(Queue &q, Stack &s)
{

    while (!stack_isempty(s))
    {
        insert_queue(q, pop_stack(s));
    }
    insert_queue(q, remove_queue(q));
    insert_queue(q, remove_queue(q));
    display_queue(q);
}

bool generate_code(Node *root, string &code, char target)
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
    if (generate_code(root->left, code, target))
    {
        return true;
    }
    else
    {
        code.pop_back();
    }

    code.push_back('1');
    if (generate_code(root->right, code, target))
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
        generate_code(tree.getroot(), code, target);
        list.insert_into_linkedlist(target, code);
    }
}

// Decryption Functions
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
void code_to_char(BST &tree, Queue &q, Linked_list &list)
{
    Linkedlist_Node *ptr = list.front;
    while (ptr != nullptr)
    {
        char ch = decode_msg(tree, ptr->binarycode);
        insert_queue(q, ch);
        ptr = ptr->next;
    }
}
void queue_reverse_shifting(Queue &q, Stack &s)
{
    int n = q.rear - q.front + 1;
    for (int i = 0; i < n - 2; i++)
    {
        insert_queue(q, remove_queue(q));
    }
}

void reverse(Queue &q,Stack &s){
    while (!queue_isempty(q))
    {
        push_stack(s,remove_queue(q));
    }
    reverse_stack_with_ref(s);
}