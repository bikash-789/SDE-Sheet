#include <iostream>
using namespace std;

template <typename T>
class LinkedListNode
{
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
};

LinkedListNode<int>* takeInput()
{
    LinkedListNode<int> *head = NULL, *tail=NULL;
    int data;
    cin>>data;
    while(data!=-1)
    {
        LinkedListNode<int>* node = new LinkedListNode<int>(data);
        if(!head) 
        {
            head = node;
        }
        else 
        {
            tail->next = node;
        }
        tail=node;
        cin>>data;
    }
    return head;
}


bool detectCycle(LinkedListNode<int> *head)
{
    //initialize two pointer slow and fast
    LinkedListNode<int>* slow = head, *fast = head;
    if(!slow || !slow->next) return false;
    while(fast->next!=NULL && fast->next->next != NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    LinkedListNode<int>* head = takeInput();
    cout<<detectCycle(head)<<endl;
}