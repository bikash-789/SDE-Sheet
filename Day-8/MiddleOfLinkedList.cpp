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


LinkedListNode<int> *findMiddle(LinkedListNode<int> *head) 
{
    if(!head) return head;
    LinkedListNode<int> *slow = head, *fast=head;
    while(fast && !(fast->next==NULL))
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

int main()
{
    LinkedListNode<int> *head = takeInput();
    cout<<(findMiddle(head))->data<<endl;
}