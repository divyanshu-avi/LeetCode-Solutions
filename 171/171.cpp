class Solution {
public:
    int titleToNumber(string s) {
        
        int n = s.size();
        int ans = 0;
        long long int multiplier= 1;
        
        for(int i =n-1; i>=0 ; i--){
            
            int n = s[i]-'A'+1;
            ans += n*multiplier;
            multiplier*=26;
            
        }
        
        
        return ans;
    }
};