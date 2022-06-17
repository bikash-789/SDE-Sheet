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
LinkedListNode<int>* sortTwoLists(LinkedListNode<int>* first, LinkedListNode<int>* second)
{
    if(!first) return second;
    if(!second) return first;

    LinkedListNode<int> *t1=first, *t2=second, *head=NULL, *tail=NULL;

    while(t1 && t2)
    {
        if(t1->data < t2->data)
        {
            if(!head) head=t1;
            else tail->next = t1;
            tail=t1;
            t1=t1->next;
        }
        else
        {
            if(!head) head=t2;
            else tail->next = t2;
            tail=t2;
            t2=t2->next;
        }
    }
    while(t1)
    {
        tail->next = t1;
        tail=t1;
        t1=t1->next;
    }
    while(t2)
    {
        tail->next = t2;
        tail=t2;
        t2=t2->next;
    }
    tail->next = NULL;

    return head;
}
void printLL(LinkedListNode<int> *head)
{
    LinkedListNode<int> *temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    LinkedListNode<int> *head1 = takeInput();
    LinkedListNode<int> *head2 = takeInput();

    LinkedListNode<int>* sortedHead = sortTwoLists(head1, head2);
    printLL(sortedHead);
    cout<<endl;
}