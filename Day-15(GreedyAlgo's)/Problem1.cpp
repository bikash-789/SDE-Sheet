#include <iostream>
using namespace std;

//Problem Link: https://www.codechef.com/submit/RAMDEV

/*

Sample Input 1:
4 4 (l, b) dimension of mats
1 (N) no. of halls
4 12 (L, B) dimension of halls

Sample Output 1:
3


*/



int main()
{
    int l,b, N;
    cin>>l>>b>>N;
    int ans=0;
    for(int i=0; i<N; i++)
    {
        int L, B;
        cin>>L>>B;
        ans += max(((L/l) * (B/b)), ((L/b) * (B/l)));
    }
    cout<<ans<<endl;
}