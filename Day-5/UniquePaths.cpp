#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
	// Write your code here.
    int **dp = new int*[m+1];
    for(int i=0; i<(m+1); i++)
    {
        dp[i] = new int[n+1];
    }
    
    for(int i=m-1; i>=0; i--)
    {
        for(int j=n-1; j>=0; j--)
        {
            if(i==m-1 && j==n-1) dp[i][j]=1;
            else dp[i][j] = dp[i][j+1] + dp[i+1][j];
        }
    }
    return dp[0][0];
}

int main()
{
    int m,n;
    cin>>m>>n;
    cout<<uniquePaths(m,n)<<endl;
}