#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/*
Problem Link: https://www.codechef.com/submit/SAVKONO
*/



int main() {
    priority_queue<int> pq;
    int T;
    cin>>T;
    
    while(T--)
    {
        
        int N, K, val;
        cin>>N>>K;
        vector<int> soldiers;
        for(int i=0; i<N; i++)
        {
            cin>>val;
            soldiers.push_back(val);
            pq.push(val);
        }
        
        int i=0, count=0, f=0;
        while(!pq.empty())
        {
            count++;
            int top = pq.top();
            pq.pop();
            K = K - top;
            top = top/2;
            if(top > 0) pq.push(top);
            if(K <= 0) {
                f=1;
                break;
            }
        }
        if(!f) cout<<"Evacuate"<<endl;
        else cout<<count<<endl;
        pq = priority_queue<int>();
    }
}
