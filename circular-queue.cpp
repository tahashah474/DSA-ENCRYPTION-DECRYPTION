#include <iostream>
using namespace std;

const int q_size = 100;
struct Queue
{
    char arr[q_size];
    int front;
    int rear;
};

bool queue_isempty(Queue &q)
{
    return (q.front == -1);
}
bool isfull(Queue &q)
{
    return ((q.front == 0 && q.rear == q_size - 1) || (q.rear + 1 == q.front));
}
void insert_queue(Queue &q, char n)
{
    if (isfull(q))
    {
        cout << "Queue is Full" << endl;
        return;
    }
    else if (q.front == -1)// first value
    {
        q.front = 0;
        q.rear = 0;
    }
    else if (q.front != 0 && q.rear == q_size - 1)//wrap around
    {
        q.rear = 0;
    }
    else
    {
        q.rear++;
    }
    q.arr[q.rear] = n;
}
char remove_queue(Queue &q)
{
    if (queue_isempty(q))
    {
        cout << "Queue is Empty" << endl;
        return '\0';
    }
    char value = q.arr[q.front];
    if (q.front == q.rear)
    {
        q.rear = -1;
        q.front = -1;
    }
    else if (q.front == q_size - 1)//wrap around case
    {
        q.front = 0;
    }
    else
    {
        q.front++;
    }
    return value;
}

void display_queue(Queue &q)
{
    if (queue_isempty(q))
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    if (q.rear >= q.front)
    {
        for (int i = q.front; i <= q.rear; i++)
        {
            cout << q.arr[i] << " ";
        }
    }
    else
    {

        for (int i = 0; i <= q.rear; i++)
        {
            cout << q.arr[i] << " ";
        }
        for (int i = q.front; i < q_size; i++)///There might be  a  flaw in this part
        {
            cout << q.arr[i] << " ";
        }
    }
    cout << endl;
}