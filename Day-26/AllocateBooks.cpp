#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
                 
bool isPossible(ll mid, vector<int> &time, int n)
{
    ll dayLimit = 0;
    int dayCount = 1;
    for(int i=0; i<time.size(); i++)
    {
        if((ll)(time[i]) > mid) return false;
        if((dayLimit + (ll)(time[i])) <= mid)
        {
            dayLimit += (ll)(time[i]);
         }
        else {
            dayCount++;
            if(dayCount > n || time[i]>mid) return false;
            dayLimit = (ll)(time[i]);
        }
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    ll low=time[0], high=0;
    for(int i=0; i<m; i++)
    {
        low = min(low, (ll)(time[i]));
        high += (ll)(time[i]);
    }
    
    ll ans = -1;
    while(low<=high)
    {
        //low to high is the time limit ayush can have
        
        //let's bound his time limit to [low+high/2] a day
        ll mid = (low+high) >> 1;
        
        //now ask if he can complete the syllabus in 'n' days
        if(isPossible(mid, time, n))
        {
            ans = mid;
            high = mid-1;
        }
        else low = mid+1; //else he needs to increase the time limit
    }
    return ans;
}
