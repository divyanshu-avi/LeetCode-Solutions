class Solution {
public:
    static bool myCompare(vector<int> A, vector<int> B)
    {
        return A[0]<B[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size(), i, idx;
        vector<vector<int>> ans;
        if(!n)
            return ans;
        
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(i=1;i<n;i++)
        {
            //Only need to check with last index because sorted.
            if(intervals[i][0]<=ans.back()[1])//If overlaps
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            else
                ans.push_back(intervals[i]);
        }
        return ans;
    }
};