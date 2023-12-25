#include <bits/stdc++.h>
using namespace std;

/*

**************.  Recursive solution -> Memoized version.  ***************


int helperFunc(int day, int prevTask, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    // base case
    if(day == 0)
    {
        int maxPoints = 0;
        for(int i=0; i<3; i++)
        {
            if(i!=prevTask)
            {
                maxPoints = max(maxPoints, points[day][i]);
            }
        }
        return maxPoints;
    }

    if(dp[day][prevTask] != -1) return dp[day][prevTask];
    
    // do for n-th and let recursion do for (n-1)th
    int maxPoints = 0;
    for(int i=0; i<3; i++)
    {
        if(i!=prevTask)
        {
            int todayPoints = points[day][i] + helperFunc(day-1, i, points, dp);
            maxPoints = max(todayPoints, maxPoints);
        }
    }
    return dp[day][prevTask] = maxPoints;
}
*/
int ninjaTraining(int n, vector<vector<int>> &points)
{  
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1; day<n; day++)
    {
    	// we are filling the dp columnwise: what could be the maximum possible points on the given day by performing activity 'last' on previous day
        for(int last = 0; last<4; last++)
        {
            dp[day][last] = 0;
            for(int task=0; task<3; task++)
            {
                if(task!=last)
                {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(point, dp[day][last]);
                }
            }
        }
    }
    return dp[n-1][3];

}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	vector<vector<int>> points(n, vector<int>(3, 0));
	int temp;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<3; j++)
		{
			cin>>temp;
			points[i][j] = temp;
		}
	}
	cout<<ninjaTraining(n, points)<<endl;
}