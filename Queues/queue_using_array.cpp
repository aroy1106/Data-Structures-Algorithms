#include <iostream>
using namespace std;

#define MAX 10

class Queue
{
private:
    int *data;
    int front;
    int rear;

public:
    Queue()
    {
        data = new int[MAX];
        front = rear = -1;
    }
    int enqueue(int value)
    {
        if (rear == (MAX - 1))
        {
            cout << "Queue Overflow!\n";
            return 1;
        }
        else
        {
            if (front == -1)
                front++;

            rear++;
            data[rear] = value;
            return 0;
        }
    }
    int dequeue()
    {
        if (front > rear)
        {
            cout << "Queue Undeflow!\n";
            return 1;
        }
        else
        {
            front++;
            return 0;
        }
    }
    void peek()
    {
        int i;
        for (i = front; i < rear + 1; i++)
            cout << data[i] << " ";
    }
};

int main()
{
    Queue q;
    int v;

    cout << "Enter a value you want to add: ";
    cin >> v;
    q.enqueue(v);

    char choice = 'a';

    while (choice != 'n')
    {
        cout << "Do you want to continue?(y/n) ";
        cin >> choice;

        if (choice == 'y')
        {
            cout << "Enter the value you want to add: ";
            cin >> v;

            int res = q.enqueue(v);

            if (res == 1)
                break;
        }
    }
    cout << "\nThe data stored in the queue is: ";
    q.peek();
    cout << "\nAfter first deletion, the final data is: ";
    q.dequeue();
    q.peek();
    cout << "\nAfter second deletion, the final data is: ";
    q.dequeue();
    q.peek();
    cout << endl;

    return 0;
}