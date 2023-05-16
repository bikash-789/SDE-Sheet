#include <iostream>
#include <queue>


using namespace std;

// For push operation: 
// 1. Add into queue
// 2. For every i-1 elements into queue 
// pop and push again into queue

class StackUsingQueue{
    int size;
    int cnt;
    queue<int> q;

public:
    StackUsingQueue(int size)
    {
        this->size = size;
        cnt = 0;
    }

    // isEmpty method
    bool isEmpty()
    {
        if(cnt == 0) return true;
        return false;
    }
    // isFull method
    bool isFull()
    {
        if(cnt == size)
        {
            return true;
        }
        return false;
    }
    // Push method
    void pushIntoStack(int elem)
    {
        if(!isFull())
        {
            q.push(elem);
            cnt++;

            for(int i=0; i<cnt-1; i++)
            {
                q.push(q.front());
                q.pop();
            }
        }
    }

    // void pop method
    void popFromStack()
    {
        if(!isEmpty()) {
            q.pop();
            return;
        }
        cout<<"Stack is empty!"<<endl;
        return;
    }
    
    // top method
    int topInStack()
    {
        if(!isEmpty()){
            return q.front();
        }
        cout<<"Stack is empty!"<<endl;
        return -1;
    }

};


int main()
{
    StackUsingQueue *st = new StackUsingQueue(4);
    st->pushIntoStack(5);
    st->pushIntoStack(1);
    st->pushIntoStack(4);
    // st->popFromStack();
    cout<<st->topInStack()<<endl;
}