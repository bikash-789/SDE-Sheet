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



LinkedListNode<int> *getListAfterReverseOperation(LinkedListNode<int> *head, int n, int b[])
{
    LinkedListNode<int> *current=head, *tail = NULL, *join = current, *prev = NULL;
    bool isNewHead = false;
    int idx = 0;
    while(current!=NULL && idx < n)
    {
        //store idx-th value of b in variable
        int K = b[idx];
        
        if(K==0)
        {
            idx++;
            continue;
        }

        //reverse the linked list upto K
        join = current;
        prev = NULL;
        while(current!=NULL && K--)
        {
            LinkedListNode<int> *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        //check if the new head is updated or not
        if(!isNewHead)
        {
            head = prev;
            isNewHead=true;
        }

        if(tail != NULL)
        {
            tail->next = prev;
        }

        tail = join;
        idx++;
    }
    if(tail!=NULL)
    {
        tail->next = current;
    }
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
    int n;
    LinkedListNode<int> *head = takeInput();
    cin>>n;
    int b[n];
    for(int i=0; i<n; i++)
        cin>>b[i];

    head = getListAfterReverseOperation(head, n, b);
    printLL(head);
    cout<<endl;
}   