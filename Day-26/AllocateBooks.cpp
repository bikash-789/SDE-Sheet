#include <iostream>
#include <vector>

using namespace std;

bool isPossible(int mid, vector<int> &time, int n)
{
    int dayLimit = 0;
    int daysLeft = 0;
    for(int i=0; i<time.size(); i++)
    {
        if(time[i] > mid) return false;
        if((dayLimit + time[i]) > mid)
        {
            dayLimit = time[i];
            daysLeft++;
         }
        else dayLimit += time[i];
    }
    if(daysLeft > (n-1)) return false;
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    int l=time[0], h=0;
    for(int i=0; i<m; i++)
    {
        l = min(l, time[i]);
        h += time[i];
    }
    
    int low = l, high = h;
    int ans = -1;
    while(low<=high)
    {
        //low to high is the time limit ayush have
        
        //let's bound his time limit to [low+high/2] a day
        int mid = (low+high) >> 1;
        
        //now ask if he can complete the syllabus in 'n' days
        if(isPossible(mid, time, n))
        {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return (long long)(ans);
}
