#include <iostream>
#include <vector>
using namespace std;


/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

int maxProfit(vector<int> &prices)
{
    // Single day to buy and other day to sell the stock
    // Minimum price possible so far on particular day
    int bestBuyPrice = prices[0];
    int maxProfit = -999999;
    for(int i=1; i<prices.size(); i++)
    {
        // sell at this day
        maxProfit = max(maxProfit, prices[i]-bestBuyPrice);

        // keep track of bestBuyPrice
        bestBuyPrice = min(bestBuyPrice, prices[i]);
    }
    if(maxProfit < 0) return 0;
    return maxProfit;
}
int main()
{
    int n, val;
    cin>>n;

    vector<int> prices;
    while(n--)
    {
        cin>>val;
        prices.push_back(val);
    }
    cout<<maxProfit(prices)<<endl;
}