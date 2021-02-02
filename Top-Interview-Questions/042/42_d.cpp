class Solution {
public:
    int trap(vector<int>& height) {
        int i, n = height.size(), ans = 0;
        if(!n)
            return ans;
        vector<int> maxl(n), maxr(n);
        maxl[0] = height[0];
        maxr[n-1] = height[n-1];
        
        for(i=1;i<n;i++)
        {
            maxl[i] = max(height[i], maxl[i-1]);
            maxr[n-1-i] = max(height[n-1-i], maxr[n-i]);
        }
        for(i=1;i<n-1;i++)
            ans += min(maxl[i], maxr[i]) - height[i];
        return ans;
    }
};