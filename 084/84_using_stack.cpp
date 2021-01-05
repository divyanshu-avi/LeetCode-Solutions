class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int i =0;
        stack<int> p;
        stack<int> h;
        
        int maxarea = 0;
        
        heights.push_back(0);
        
        for(int i =0; i<heights.size();i++){
            
            int temp = INT_MAX;
            
            while(!h.empty() && h.top()>heights[i]){
                int curr = i-p.top();
                curr = curr*h.top();
                
                maxarea = max(maxarea,curr);
                temp = p.top();
                h.pop();
                p.pop();
            }
            
            
            if(h.empty() || h.top()<heights[i]){
            h.push(heights[i]);
            p.push(min(i,temp));
            }
            
            
        }
        return maxarea;
        
    }
};