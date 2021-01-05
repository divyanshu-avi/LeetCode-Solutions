class Solution {
public:
    int numDecodings(string s) {
        
        if (s=="0")
            return 0;
        int n = s.size();
        
        vector<int> dp(n+1,-1);
        
        dp[n]=1;
        
        if(s[n-1]=='0'){
            dp[n-1]=0;    
        }else dp[n-1]=1;
        
        cout<<dp[n-1]<<endl;
        
        for(int i = n-2;i>=0;i--){
           cout<<i<<" ";
            
            if(s[i]=='0'){
                dp[i]=0;
                cout<<dp[i]<<endl;
                continue;
               
            }
            
            dp[i]=dp[i+1];
            
            if(s[i]=='1'  && i<n-1)
                dp[i]+=dp[i+2];
            
            else if(s[i]=='2' && i<n-1){
                cout<<"executed at"<<i;
                if(s[i+1]>='0' && s[i+1]<='6')
                    dp[i]+=dp[i+2];
            }
            
            cout<<dp[i]<<endl;
        }
       return dp[0]; 
    }
};