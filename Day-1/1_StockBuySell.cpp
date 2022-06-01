#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(vector<int> &prices)
{
    int maxProfit=0;
    int minPriceSoFar=prices[0];
    for(int i=1; i<prices.size(); i++)
    {
        minPriceSoFar = min(minPriceSoFar, prices[i]);
        maxProfit = max(maxProfit, prices[i]-minPriceSoFar);
    }
    return maxProfit;
}


int main()
{
    int n;
    cin>>n;
    int val;
    vector<int> prices;
    for(int i=0; i<n; i++)
    {
        cin>>val;
        prices.push_back(val);
    }
    cout<<maximumProfit(prices)<<endl;
}