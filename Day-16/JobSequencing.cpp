#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool comp(vector<int> v1, vector<int> v2)
{
    return v1[1] >= v2[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    //create an array of struct job
    int n=jobs.size();
    sort(jobs.begin(), jobs.end(), comp);
    
    //find the value with maximum deadline
    int val=0, i=0;
    while(i<n)
    {
        val = max(val, jobs[i][0]);
        i++;
    }
    //create an array of size maxDeadline 
    int temp[val];
    for(int i=0; i<val; i++)
        temp[i] = -1;
    
    
    for(int i=0; i<n; i++)
    {
        if(temp[jobs[i][0]-1] == -1)
        {
            temp[jobs[i][0]-1] = i;
        }
        else
        {
            //travel to the left and find the empty location i.e. find where -1
            int j=jobs[i][0]-2;
            while(j>=0)
            {
                if(temp[j]==-1)
                {
                    temp[j]=i;
                    break;
                }
                j--;
            }
        }
    }
    //now sum all values {jobs[temp[i]][1]} in temp which aren't equal to -1
    int maxProfit = 0;
    for(int i=0; i<val; i++)
    {
        if(temp[i] != -1)
            maxProfit += jobs[temp[i]][1];
    }
    return maxProfit;
    
}


int main()
{
    int n;
    cin>>n;

    vector<vector<int>> jobs;
    for(int i=0; i<n; i++)
    {   
        vector<int> job;
        int val;
        cin>>val;
        job.push_back(val);
        jobs.push_back(job);
    }
    for(int i=0; i<n; i++)
    {   
        int val;
        cin>>val;
        jobs[i].push_back(val);
    }

    cout<<jobScheduling(jobs)<<endl;

}