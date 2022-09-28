#include <iostream>
#include <vector>

#include "MinHeap.h"


using namespace std;

int main()
{
    //let's create a min heap object
    MinHeap pq = MinHeap();
    pq.push(56);
    pq.push(24);
    pq.push(32);
    pq.push(4);
    cout<<pq.pop()<<endl;
    cout<<pq.pop()<<endl;
    cout<<pq.pop()<<endl;
    cout<<pq.pop()<<endl;
    cout<<pq.top()<<endl;

    cout<<pq.getSize()<<endl;

}