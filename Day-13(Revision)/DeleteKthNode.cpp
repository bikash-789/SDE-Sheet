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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    //Initialize two nodes as fast and slow
    LinkedListNode<int> *fast = head, *slow = NULL;

    while(--K)
    {
        fast = fast->next;
    }
    
    while(fast->next != NULL)
    {
        fast=fast->next;
        if(!slow) slow=head;
        else slow=slow->next;
    }
    if(!slow) 
    {
        head=head->next;
    }
    else slow->next = slow->next->next;
    return head;
}

void printLL(LinkedListNode<int>* head)
{
    LinkedListNode<int> *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{   
    int K;
    cin>>K;
    LinkedListNode<int>* head = takeInput();
    head = removeKthNode(head, K);
    printLL(head);
}