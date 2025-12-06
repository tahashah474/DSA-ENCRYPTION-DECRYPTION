#include <iostream>
using namespace std;

const int stack_size = 100;
struct Stack
{
    char arr[stack_size];
    int top;
};

bool isfull(Stack &s)
{
        return s.top == stack_size - 1;
}
void push_stack(Stack &s, char value)
{
    if (!isfull(s))
    {
        s.arr[++s.top] = value;
    }
    else
    {
        cout << "Stack is full" << endl;
    }
}
bool stack_isempty(Stack &s)
{
        return s.top == -1;
}
char pop_stack(Stack &s)
{
    if (stack_isempty(s))
    {
        cout << "Stack is empty" << endl;
        return '\0';
    }
    
   return s.arr[s.top--];
}



void stack_display( Stack &s)
{
     if (stack_isempty(s))
    {
        cout << "Stack is empty" << endl;
        return ;
    }
    for (int i = 0; i <=s.top; i++)
    {
        cout << s.arr[i] << " ";
    }
    cout << endl;
}
void reverse_stack(Stack s)
{
    Stack temp;
    temp.top=-1;
    while (!stack_isempty(s))
    {
       push_stack(temp,pop_stack(s));
    }
    s=temp;
    stack_display(s);
}
void reverse_stack_with_ref(Stack &s)
{
    Stack temp;
    temp.top=-1;
    while (!stack_isempty(s))
    {
       push_stack(temp,pop_stack(s));
    }
    s=temp;
   
}