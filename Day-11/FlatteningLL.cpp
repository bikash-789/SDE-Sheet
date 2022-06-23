#include <iostream>
using namespace std;

template <typename T>
class Node
{
    public:
        T data;
        Node<T> *next;
        Node<T> *child;
        Node(T data)
        {
            this->data = data;
            this->child = NULL;
            this->next = NULL;
        }
};

Node<int>* mergeTwoLL(Node<int>* l1, Node<int>* l2)
{
    Node<int>* temp = new Node<int>(0);
    Node<int> *res = temp;
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->data < l2->data)
        {
            temp->child = l1;
            temp = l1;
            l1 = l1->child;
        }
        else
        {
            temp->child = l2;
            temp = l2;
            l2 = l2->child;
        }
    }
    if(l1) temp->child = l1;
    else temp->child = l2;
    
    return res->child;
}

//The main idea is to call recursion until the single LL is reached, after that merge the last two LL and return the new Head
Node<int>* flattenLinkedList(Node<int>* head) 
{
	if(head==NULL || head->next == NULL)
    {
        return head;
    }
    
    head->next = flattenLinkedList(head->next);  
    head = mergeTwoLL(head, head->next);
    return head;
}

