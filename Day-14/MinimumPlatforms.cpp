#include <iostream>
#include <algorithm>
using namespace std;


int calculateMinPatforms(int at[], int dt[], int n) {
    //initially sort both the arrivalTime and departureTime array
    sort(at, at+n);
    sort(dt, dt+n);

    int i=0, j=0, localCount=0, maxCount = 0;
    while(i<n)
    {
        if(at[i] > dt[j])
        {
            localCount--;
            j++;
        }
        else if(at[i] <= dt[j])
        {
            localCount++;
            i++;
        }
        maxCount = max(maxCount, localCount);
    }
    return maxCount;
}

int main()
{
    int n;
    cin>>n;

    int at[n], dt[n];
    for(int i=0; i<n; i++)
    {
        cin>>at[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>dt[i];
    }
    cout<<calculateMinPatforms(at, dt, n)<<endl;
}