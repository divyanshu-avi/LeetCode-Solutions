class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        q.push({nums[0], 0});
        for(int i=1;i<k;i++){
            if(q.top().first<nums[i]) q=priority_queue<pair<int,int>>();
            q.push({nums[i], i});
        }
        vector<int> ans;
        ans.push_back(q.top().first);
        for(int i=k;i<nums.size();i++){
            if(nums[i]>q.top().first){
                q=priority_queue<pair<int,int>>();
                q.push({nums[i],i});
            }
            else{
                q.push({nums[i], i});
                while(q.top().second<i-k+1)
                    q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};
