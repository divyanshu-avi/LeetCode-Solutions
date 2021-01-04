class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> vec;
        solve(ans,vec,n,0,nums);
        
        return ans;
    }
    
    void solve(vector<vector<int>> &ans,vector<int> &temp,int &size, int posi,vector<int> &nums){
        
        if(size+1==posi)
            return;
        
        ans.push_back(temp);
        
        for(int i =posi; i<size; i++){
            temp.push_back(nums[i]);
            solve(ans,temp,size,i+1,nums);
            temp.pop_back();
        }
        
        return;
        
    }
};