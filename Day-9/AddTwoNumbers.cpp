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

LinkedListNode<int>* addTwoNumbers(LinkedListNode<int>* head1, LinkedListNode<int>* head2)
{
    //
    LinkedListNode<int>* d1 = head1, *d2 = head2, *fHead=NULL, *fTail=NULL;
    int carry=0, sum=0;
    
    while(d1 && d2)
    {
        sum = ( carry + d1->data + d2->data ) % 10;
        carry = (carry + d1->data + d2->data) / 10;
        
        LinkedListNode<int>* newNode = new LinkedListNode<int>(sum);
        
        if(!fHead) fHead=newNode;
        else fTail->next = newNode;
        fTail = newNode;
        
        d1=d1->next;
        d2=d2->next;
    }
    
    while(d1)
    {
        sum = (carry + d1->data)%10;
        carry = (carry + d1->data)/10;
        LinkedListNode<int>* newNode = new LinkedListNode<int>(sum);
        fTail->next = newNode;
        fTail = newNode;
        d1=d1->next;
    }
    while(d2)
    {
        sum = (carry + d2->data)%10;
        carry = (carry + d2->data)/10;
        LinkedListNode<int>* newNode = new LinkedListNode<int>(sum);
        fTail->next = newNode;
        fTail = newNode;
        d2=d2->next;
    }
    if(carry!=0)
    {
        LinkedListNode<int>* newNode = new LinkedListNode<int>(carry);
        fTail->next = newNode;
        fTail=newNode;
    }
    return fHead;
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
    LinkedListNode<int> *outputHead = addTwoNumbers(head1, head2);
    printLL(outputHead);
    cout<<endl;
}