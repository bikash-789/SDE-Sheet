#include <iostream>
#include "MaxHeap.h"

using namespace std;


int main()
{
    MaxHeap heap = MaxHeap();
    //cout << heap.getSize() <<endl;
    heap.push(5);
    //cout<<heap.getSize()<<endl;
    heap.push(54);
    heap.push(43);
    heap.push(56);
    cout<<heap.pop()<<endl;
    cout<<heap.pop()<<endl;
    cout<<heap.pop()<<endl;
    cout<<heap.pop()<<endl;
    cout<<heap.getSize()<<endl;
}