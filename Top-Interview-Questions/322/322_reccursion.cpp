class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        
        sort(coins.begin(), coins.end());
        vector<int> a(amount+1,0);
        return solve(coins,amount,a);
        
    }
    
    int solve(vector<int>& coins, int target, vector<int>&a){
        
        if(target==0)
            return 0;
        if(target<0)
            return -1;
        if(a[target]!= 0)
            return a[target];
        
        int mini = INT_MAX;
        int temp;
        
        for(int j =0; (j < coins.size() && target-coins[j]>=0); j++){
            
            temp = solve(coins,target - coins[j],a);
              if(temp != -1)  
            mini = min(mini, 1+ temp );
            
        }
        
        if(mini!= INT_MAX)
        a[target] = mini;
        else
        a[target] = -1;
        
        return a[target];
        
    }
    
};