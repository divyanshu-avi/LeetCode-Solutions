class Solution {
public:
    vector<vector<string>> partition(string s) {
      
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,0,0,ans,temp);
        return ans;
        
    }
    
    void solve(string& s, int l, int r,vector<vector<string>>& ans,vector<string>& temp){
        
        if(r==s.size()){
            if(l==s.size())
            ans.push_back(temp);
            return;
        }
        
        while(r<s.size()){
            
            if(isPalindrome(l,r,s)){
                temp.push_back(s.substr(l,r-l+1));
                solve(s,r+1,r+1,ans,temp);
                temp.pop_back();
            }
            r++;
        }
        
        return;
        
        
    }
    
    bool isPalindrome(int l, int r, string& s){
        
        while(l<=r){
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
        
    }
    
};