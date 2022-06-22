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


bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    
    //find the middle of the linked list
    LinkedListNode<int> *slow = head, *fast = head;
    if(!head) return true;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    //reverse the linked list after slow i.e from slow->next
    LinkedListNode<int> *current = slow->next, *temp=NULL, *prev = NULL;
    while(current != NULL)
    {
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    
    slow = head;
    while(prev != NULL)
    {
        if(slow->data != prev->data)
        {
            return false;
        }
        prev=prev->next;
        slow=slow->next;
    }
    return true;
}

int main()
{
    LinkedListNode<int> *head = takeInput();
    if(isPalindrome(head))
        cout<<"True"<<endl;
    else cout<<"False"<<endl;
}