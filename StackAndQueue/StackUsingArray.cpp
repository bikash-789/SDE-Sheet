#include <iostream>
#include <vector>
using namespace std;


class Stack {
    int top;
    int size;
    vector<int> arr;

public:
    // Constructor
    Stack(int s)
    {
        this->size = s;
        this->top = -1;
    }

    // Method to check if the stack is empty
    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        return false;
    }

    // Method to check if the stack is full
    bool isFull()
    {
        if(top == size-1)
        {
            return true;
        }
        return false;
    }

    // Method to push into stack
    void push(int val)
    {
        if(!isFull())
        {
            arr.push_back(val);
            top++;
            return;
        }
        cout<<"Stack is full!"<<endl;
    }

    // Method to pop from stack
    int pop()
    {
        if(!isEmpty())
        {
            return arr[top--];
        }
        cout<<"Stack is empty!";
        return -1;
    }

    // Method to return top element of stack
    int peek()
    {
        if(!isEmpty()) return arr[top];
        cout<<"Stack is empty!";
        return -1;
    }
};

int main()
{
    Stack *s = new Stack(4);
    s->push(5);
    s->push(10);
    cout<<s->pop()<<endl;
    cout<<s->peek()<<endl;
    cout<<s->pop()<<endl;
    cout<<s->pop()<<endl;
}