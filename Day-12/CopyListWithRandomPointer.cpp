#include <iostream>
using namespace std;

template <typename T>
class LinkedListNode
{
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
};

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(!head) return head;
    //create copy of nodes
    LinkedListNode<int> *temp = head;
    while(temp!=NULL)
    {
        //create new node
        LinkedListNode<int> *copyNode = new LinkedListNode<int>(temp->data);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = copyNode->next;
    }
    
    //set the value of random pointers of copied nodes
    LinkedListNode<int> *front=head->next->next;
    temp = head;
    while(temp!=NULL)
    {
        if(temp->random!=NULL)
        {
            temp->next->random = temp->random->next;
        }
        else temp->next->random = NULL;
        temp=front;
        if(front) front=front->next->next;
    }
    
    
    //disconnect every node's(original) next with copied nodes
    LinkedListNode<int> *newHead = NULL, *tail = NULL;
    front = head->next->next;
    temp = head;
    while(temp!=NULL)
    {
        if(!newHead)
        {
            newHead = temp->next;
        }
        else tail->next = temp->next;
        tail=temp->next;
        
        temp->next = tail->next;
        temp = front;
        if(front) front=front->next->next;
    }
    return newHead;
}

