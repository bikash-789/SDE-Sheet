#include <iostream>
using namespace std;

/*
Problem Statement
You are given a three integers 'X', 'N', and 'M'. 
Your task is to find ('X' ^ 'N') % 'M'. 
A ^ B is defined as A raised to power B and A % C is the remainder when A is divided by C.
*/

int modularExponentiation(int x, int n, int m) {
    int ans = 1;
    while(n)
    {
        if(n&1)
        {
            ans = (1LL * ans * x)%m;
        }
        x = (1LL * x * x)%m;

        // Right shift 'N' by 1 bit for next iteration.
        n>>=1;
    }
    return ans;
}
int main()
{
    int x,n,m;
    cin>>x>>n>>m;
    cout<<modularExponentiation(x,n,m)<<endl;
}