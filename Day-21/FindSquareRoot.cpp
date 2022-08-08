#include <iostream>

using namespace std;

int multiply(double a, int n)
{
    double ans = 1.0;
    for(int i=0; i<n; i++)
        ans = ans*a;

    return ans;
}


//define a function 
double findSqrt(int m, int n)
{
    //find n^(1/m) 
    double s=1.0, e=n;

    while((e-s) > 1e-8)
    {
        double mid = (e+s)/2.0;
        double ans = multiply(mid, m);
        if(ans < n) s=mid;
        else e=mid;
    }
    return e;
}

int main()
{
    //
    int m, n;
    cin>>m>>n;

    cout<<findSqrt(m, n)<<endl;
}