#include <iostream>
using namespace std;

double multiply(double num, int n)
{
    //find num to the power of n
    double ans = 1.0;
    for(int i=0; i<n; i++)
    {
        ans *= num;
    }
    return ans;
}

double findNthRoot(int m, int n)
{
    double l=1.0, h=1.0*m;
    while((h-l)>1e-9)
    {
        double mid = (l+h)/2.0;
        double ans = multiply(mid, n);
        if(ans < m) l=mid;
        else h=mid;
    }
    return h;
}


int main()
{
    int m, n;
    cin>>m>>n;
    double ans = findNthRoot(m, n);
    cout<<ans<<endl;
}