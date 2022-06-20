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
/*
Problem Statement
Suggest Edit
You are given two Singly Linked List of integers, which are merging at some node of a third linked list.
Your task is to find the data of the node at which merging starts. If there is no merging, return -1.
*/

int findIntersection(LinkedListNode<int> *firstHead, LinkedListNode<int> *secondHead)
{
    //length of linked list 1
    int c1=0, c2=0;
    LinkedListNode<int> *temp1 = firstHead, *temp2 = secondHead;
    while(temp1)
    {
        temp1=temp1->next;
        c1++;
    }
    while(temp2)
    {
        temp2=temp2->next;
        c2++;
    }
    
    bool firstLLGreater = false;
    c1>c2?firstLLGreater=true:firstLLGreater=false;
    
    int diff = abs(c2-c1);
    
    LinkedListNode<int>* t1=firstHead, *t2=secondHead;
    c1=0;
    if(firstLLGreater)
    {
        while(c1!=diff)
        {
            t1=t1->next;
            c1++;
        }
    }
    else
    {
        while(c1!=diff)
        {
            t2=t2->next;
            c1++;
        }
    }
    
    //compare t1 and t2 location
    while(t1 && t2)
    {
        if(t1==t2)
        {
            return t1->data;
        }
        t1=t1->next;
        t2=t2->next;
    }
    return -1;
}

int main()
{
    LinkedListNode<int> *head1 = takeInput();
    LinkedListNode<int> *head2 = takeInput();
    cout<<findIntersection(head1, head2)<<endl;
}