class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX, i, n = prices.size(), profit = 0;
        for(i=0;i<n;i++)
        {
            buy = min(prices[i], buy);
            profit = max(prices[i]-buy, profit);
        }
        return profit;
    }
};