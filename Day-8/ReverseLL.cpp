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

LinkedListNode<int> *reverseLL(LinkedListNode<int> *head)
{
    if(!head || !(head->next)) return head;
    LinkedListNode<int> *current=head, *prev=NULL, *next=head->next;
    while(next)
    {
        current->next = prev;
        prev=current;
        current=next;
        next=next->next;
    }
    current->next = prev;
    return current;
}

int main()
{
    LinkedListNode<int> *head = takeInput();
    LinkedListNode<int> *newHead = reverseLL(head);
    LinkedListNode<int> *temp=newHead;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }


}