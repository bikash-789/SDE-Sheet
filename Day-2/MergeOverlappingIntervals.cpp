#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compareInterval(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}
vector<vector<int> > mergeIntervals(vector<vector<int> > &intervals)
{
    //sort the intevals
    sort(intervals.begin(), intervals.end(), compareInterval);
    vector<vector<int> > output;
    if(intervals.size()==0) return output;

    vector<int> current = intervals[0];
    
    for(int i=1; i<intervals.size(); i++)
    {
        if(current[1]>=intervals[i][0])
        {
            current[1] = max(intervals[i][1], current[1]);
        }
        else
        {
            output.push_back(current);
            current = intervals[i];
        }
    }
    output.push_back(current);
    return output;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int> > intervals;
    for(int i=0; i<2; i++)
    {
        
        for(int j=0; j<n; j++)
        {
            if(i==0)
            {
                vector<int> row;
                int val;
                cin>>val;
                row.push_back(val);
                intervals.push_back(row);
            }
            else
            {
                int val;
                cin>>val;
                intervals[j].push_back(val);
            }   
        }
    }

    vector<vector<int> > output = mergeIntervals(intervals);
    for(int i=0; i<output.size(); i++)
    {
        cout<<output[i][0]<<" "<<output[i][1]<<endl;
    }
}