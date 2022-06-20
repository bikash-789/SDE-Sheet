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


void deleteNode(LinkedListNode<int> * node) {
    // Write your code here
    node->data = node->next->data;
    node->next = node->next->next;
    
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
    LinkedListNode<int> *head = takeInput();
    int input;
    cin>>input;
    LinkedListNode<int> *temp = head;
    while(temp->data != input)
    {
        temp=temp->next;
    }
    deleteNode(temp);
    printLL(head);
    cout<<endl;
}