#include <iostream>
using namespace std;
#define MAX 5
int stSize = 0;
class Stack
{
    int top;
public:
    int a[MAX];
    Stack() { top = -1; }
    void push(int x);
    int pop();
    void peek();
    int isEmpty();
    int isFull();
    void display();
};
void Stack::push(int x)
{
    if (top >= (MAX - 1))
        cout << "Stack Overflow\n";
    else
    {
        a[++top] = x;
        stSize++;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow\n";

    }
    else
    {
        int x = a[top--];
        stSize--;
        return x;
    }
}

int Stack::isEmpty()
{
    if (top < 0)
        return 1;

    else
        return 0;
}

int Stack::isFull()
{
    if (top >= (MAX - 1))
        return 1;

    else
        return 0;
}

class Queue
{
public:
    Stack s1;
    Stack s2;
    void enQueue(int x)
    {
        s1.push(x);
    }
    void deQueue()
    {
        int x;
        if (s2.isEmpty())
        {
            if (s1.isEmpty())
            {
                cout << "Queue is empty";
                return;
            }
            else
            {
                while (!s1.isEmpty())
                    s2.push(s1.pop());
                x = s2.pop();

                while (!s2.isEmpty())
                    s1.push(s2.pop());
                cout << x << " deleted from queue";
            }
        }
    }
    void print()
    {
        int x;
        if (s2.isEmpty())
        {
            if (s1.isEmpty())
            {
                cout << "Queue is empty";
                return;
            }

            else
            {
                while (!s1.isEmpty())
                    s2.push(s1.pop());
                cout << "\nQueue elements: ";
                while (!s2.isEmpty())
                {
                    x = s2.pop();
                    cout << x << "\t";
                    s1.push(x);
                }
            }
        }
    }
};
int main()
{
    Queue q;
    int ch;
    while(1)
    {
        cout << "\n1. Enter an element \n2. Delete first element \n3. to display \n4. Exit \nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int x;
            cout << "\nEnter element: ";
            cin >> x;
            q.enQueue(x);
            break;

        case 2:
            q.deQueue();
            break;

        case 3:
            q.print();
            break;

        case 4:
            exit(1);
            break;

        default:
            cout << "\nInvalid input\n\n";
        }
    }
    return 0;
}
