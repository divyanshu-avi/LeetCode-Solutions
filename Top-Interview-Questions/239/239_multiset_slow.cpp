class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        multiset<int,greater<int>> s;
        int n = nums.size();
        int l = 0; 
        int r = k-1;
        
        multiset<int,greater<int>> :: iterator it;
        
        for(int i = 0; i< k-1 ; i++)
            s.insert(nums[i]);
        
        
        
        vector<int> ans;
        
        while(r<n){
            
            s.insert(nums[r]);
            
            cout<<s.size()<<endl;
            
            it =(s.begin());
            ans.push_back(*it);
            
            auto itr = s.find(nums[l]);
            if(itr!=s.end()){
            s.erase(itr); 
            }
            
           /* while(s.size()<k){
                s.insert(nums[l]);
            }*/
            
            
            
            l = l+1;
            r = r+1;
        }
        
        return ans;
        
    }
};