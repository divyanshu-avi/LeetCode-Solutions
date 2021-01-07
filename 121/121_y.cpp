class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = INT_MAX;
        int n = prices.size();
        
        int maxprofit =0;
        
        for(int i =0; i<n; i++){
            
            if(prices[i]<=mini){
                
                mini = prices[i];
                
            }else{
                maxprofit = max(maxprofit,prices[i]-mini);
                
            }
        }
        
        return maxprofit;
        
        
    }
};