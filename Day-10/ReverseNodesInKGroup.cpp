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

class Pair{
public:
    LinkedListNode<int> *head;
    LinkedListNode<int> *tail;
};


Pair Reverse(LinkedListNode<int> *head){
    if(head==NULL || head->next == NULL){
        Pair ans;
        ans.head= head;
        ans.tail=NULL;
        return ans;
    }
    LinkedListNode<int> *prev = NULL, *current = head, *next = head->next, *tail = head;
    while(current!=NULL){
        current->next = prev;
        prev=current;
        current=next;
        if(next!=NULL) next = next->next;
    }
    Pair ans;
    ans.head = prev;
    ans.tail = tail;
    return ans;
}

LinkedListNode<int> *getListAfterReverseOperation(LinkedListNode<int> *head, int n, int b[]){
	// Write your code here.
    if(head==NULL){
        return head;
    }
    LinkedListNode<int> *temp = head, *result=NULL, *prev=NULL, *previous=NULL, *tempHead=head;
    Pair ans;
    int k=0;
    if(n==1 && b[k]==0){
        return head;
    }
    while(temp!=NULL && k<n){
        if(b[k]==1){
             if(prev!=NULL)
            {
                prev->next = temp;
                prev = temp;
            }
            else{
                prev=temp;
                result=prev;
            }
            temp=temp->next;
            k++;
        }
        else if(b[k]==0){
            k++;
        }
        else{
            tempHead = temp;
            int i=0;
            while(temp!=NULL &&  i!=b[k]){
               i++;
               previous = temp;
               temp=temp->next;
               }
            previous->next = NULL;
            ans = Reverse(tempHead);
            if(prev==NULL){
               result = ans.head;
               prev = ans.tail;
             }
            else{
               prev->next = ans.head;
               prev = ans.tail;
             }
            k++;
    }
    }
    while(temp!=NULL){
        prev->next = temp;
        prev = temp;
        temp=temp->next;
    }
    prev->next = NULL;
    return result;
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
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    head = getListAfterReverseOperation(head, n, arr);
    printLL(head);
    cout<<endl;

}