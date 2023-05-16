#include <iostream>
using namespace std;

class Queue{
    int size;
    int front;
    int rear;
    vector<int> arr;

public:
    Queue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
    }

    // Method to check if the Queue is empty
    bool isEmpty()
    {
        if((front == rear && rear == -1) || front > rear)
        {
            front = -1;
            rear = -1;
            return true;
        }
        return false;
    }

    // Method to check if the Queue is full
    bool isFull()
    {
        if(rear == size-1)
        {
            return true;
        }
        return false;
    }

    // Method to push into Queue
    void enqueue(int val)
    {
        if(!isFull())
        {
            if(isEmpty()) front++;
            rear++;
            arr.push_back(val);
            return;
        }

        cout<<"Queue is full!"<<endl;
        return;
    }

    // Method to pop from Queue
    int dequeue()
    {
        if(!isEmpty())
        {
            return arr[front++];
        }
        cout<<"Queue is empty!"<<endl;
        return -1;
    }

    // Method to get front element
    int peek()
    {
        if(!isEmpty())
        {
            return arr[front];
        }
        cout<<"Queue is empty!"<<endl;
        return -1;
    }
};

int main()
{
    Queue *q = new Queue(4);
    q->enqueue(5); 
    q->enqueue(10);
    cout<<q->dequeue()<<endl;
    cout<<q->peek()<<endl;
    q->enqueue(11);
    q->enqueue(12);
    q->enqueue(13);
    q->enqueue(14);
    cout<<q->dequeue()<<endl;
    cout<<q->dequeue()<<endl;
    cout<<q->dequeue()<<endl;
    
}