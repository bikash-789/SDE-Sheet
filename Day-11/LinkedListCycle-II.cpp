#include <iostream>
using namespace std;

/*
You have been given a singly linked list which may or may not contain a cycle. You are supposed to return the node where the cycle begins (if a cycle exists).
A cycle occurs when a node's next pointer points back to a previous node in the list. The linked list is no longer linear with a beginning and end—instead, it cycles through a loop of nodes.
*/

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


LinkedListNode<int> *firstNode(LinkedListNode<int> *head)
{
	//    Write your code here.
    LinkedListNode<int>* slow = head, *fast = head, *entry = NULL;
    
    while(fast!=NULL && fast->next != NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast == slow)
        {
            entry = head;
            while(entry != slow)
            {
                slow=slow->next;
                entry=entry->next;
            }
            return entry;
        }
    }
    return NULL;
}

int main()
{
    LinkedListNode<int> *head = takeInput();

}