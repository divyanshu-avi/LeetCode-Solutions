class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        sort(coins.begin(), coins.end());
        
        vector<int> a(amount+1,INT_MAX);
        
        a[0] = 0;
        
        for(int i =1; i<a.size() ; i++){   
            for(int j =0; j<coins.size() && (i-coins[j])>=0 ; j++){
                
                if(a[i-coins[j]]!=INT_MAX)
                a[i] = min(a[i],1+a[i-coins[j]] );
              
            }
            cout<<a[i]<<endl;
        }
        
        return a[amount]==INT_MAX ? -1:a[amount];
    }
};
