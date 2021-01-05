class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0, i, h, n = heights.size(), left;
        stack<int> s;
        i=0;
        while(i<n || !s.empty())//Right boundary is exclusive so we need i=n if we want rightmost element included in wondow.
        {
            if(i<n && (s.empty() || heights[i] >= heights[s.top()]) ) //Inside stack we have increasing seq.
                s.push(i++);
            else
            {
                //Calculate for current element having minimum height in its window
                //For this we need nearest left and right neighbours who are less than cur element.
                h = heights[s.top()];
                s.pop();
                left = s.empty()? -1: s.top();//1st left element <= current element. Left bound of the window
                //Right boundary is i;
                ans = max(ans, h*(i-left-1));//-1 because both boundaries are exclusive.
            }
        }
        return ans;
    }
};