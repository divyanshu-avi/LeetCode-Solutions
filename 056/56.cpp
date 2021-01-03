class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        
        // sort the array so we have the left pointer orted
        // create two pointer with initial interval
            // loop till right pointer can increase
        
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> results;
        int i =0;
        int left,right;
        
        while(i<n){
            
            left = intervals[i][0];
            right = intervals[i][1];
            i++;
            
            while(i<n && left<=intervals[i][1] && right >=intervals[i][0]){
                
                right = max(right,intervals[i][1]);
                i++;
                
            }
            
            results.push_back({left,right});
            
        }
        
        return results;
        
    }
};