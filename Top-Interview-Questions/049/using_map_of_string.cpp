class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n = strs.size();
        vector<vector<string>> ans;
        
        if(n==0)
            return ans;
    
        unordered_map<string,vector<string>> mp;
        
        for(int i =0; i<n;i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(strs[i]);
        }    
        
        for(auto m : mp){
            ans.push_back(m.second);
        }
        
           
            
        
        return ans;
        
    }
};
