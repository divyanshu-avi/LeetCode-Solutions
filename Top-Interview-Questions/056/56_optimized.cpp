class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(intervals.begin(), intervals.end());
        int j=0;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(ans[j][1]>=intervals[i][0]){
                ans[j][1]=max(intervals[i][1], ans[j][i]);
                if(ans[j][1]>=intervals[i][1]){
                    continue;
                }
                else{
                    ans[j][1]=intervals[i][1];
                }
            }
            else{
                ans.push_back(intervals[i]);
                j++;
            }
        }
        return ans;
    }
};
