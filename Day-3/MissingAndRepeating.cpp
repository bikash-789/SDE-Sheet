#include <iostream>
#include <vector>

using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int res = 0;
    for(int i=1; i<=n; i++)
    {
        res = res ^ i;
    }

    for(int i=0; i<n; i++)
    {
        res = res ^ arr.at(i);
    }

    int rsb = res & (~(res-1));

    int x=0;
    int y=0;

    for(int i=0; i<n; i++)
    {
        if((arr.at(i) & rsb) == 0)
        {
            x = x^arr.at(i);
        }
        else y = y^arr.at(i);
    }

    for(int i=1; i<=n; i++)
    {
        if((i & rsb) == 0)
        {
            x = x ^ i;
        }
        else y = y ^ i;
    }
    
    pair<int,int> output;
    for(int i=0; i<n; i++)
    {
        if(arr.at(i) == x)
        {
            output.first = y;
            output.second = x;
            break;
        }
        else if(arr.at(i)==y)
        {
            output.first = x;
            output.second = y;
            break;
        }
    }
    
    return output;
}



int main()
{
    int n;
    cin>>n;
    int val;
    vector<int> input;
    for(int i=0; i<n; i++)
    {   
        cin>>val;
        input.push_back(val);
    }
    pair<int, int> output = missingAndRepeating(input, n);
    cout<<output.first<<" "<<output.second<<endl;
}