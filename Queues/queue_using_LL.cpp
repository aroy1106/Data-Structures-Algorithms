#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

void enqueue(node** front, node** rear , int v)
{
    node* cur;

    cur = new node;

    if(cur == NULL)
    {
        cout<<"Overflow\n";
        return;
    }
    else
    {
        cur->data = v;
        cur->next = NULL;

        if(*front == NULL)
            *front = * rear = cur;
        else
        {
            (*rear)->next = cur;
            *rear = cur;
        }
    }
}
void dequeue(node** front)
{
    node* ptr = *front;

    if(*front == NULL)
    {
        cout<<"Underflow\n";
        return;
    }
    *front = ptr->next;
    free(ptr);
}
void peek(node* front)
{
    if(front == NULL)
    {
        cout<<"Empty Queue";
        return;
    }
    cout<<front->data<<" ";
}

int main()
{
    node* front = NULL;
    node* rear = NULL;
    int value;
    char choice;

    cout<<"Enter the value: ";
    cin>>value;
    enqueue(&front,&rear,value);

    while(1)
    {
        cout<<"Do you wish to continue?(y/n) ";
        cin>>choice;

        if(choice == 'n')
            break;
        else
        {
            cout<<"Enter the data: ";
            cin>>value;
            enqueue(&front,&rear,value);
        }
    }
    cout<<endl<<"The queue is: ";
    peek(front);
    cout<<"\nAfter first deletion, the queue is: ";
    dequeue(&front);
    peek(front);
    cout<<"\nAfter second deletion, the queue is: ";
    dequeue(&front);
    peek(front);
    cout<<"\nAfter third deletion, the queue is: ";
    dequeue(&front);
    peek(front);
    cout<<endl;

    return 0;
}