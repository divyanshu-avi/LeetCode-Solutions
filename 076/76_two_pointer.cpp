class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size();
        int tsize = t.size();
        
        vector<int> vec(128,0);
        
        //take the amount in t
        
        for(auto x : t)
            vec[x]++;
        
        int left=0,right = 0;
        string ans;
        int min_len = INT_MAX;
        
        while(right<n){
            
            //take right, then decrease in counter, if counter value greater than = 0 decrease m.size()
            
            char c = s[right];
            //vec[c]--;
            if(--vec[c]>=0)
                tsize--;
            
            //increase the right counter;
            
            right++;
            
            //loop for left counter if the tsize = 0
            
            while(tsize==0){
                
                //check for minlen
                if(min_len>right-left){
                min_len = right-left;
                ans = s.substr(left,min_len);
                }
                
                //store usingsubstring
                
                // increase the begining char in vec
                //vec[c]++;
                
                c = s[left];
                if(++vec[c]>0)
                    tsize++;
                
                // if in vec the value is greater than zero
                    //increase tsize
                left++;
                
                //increase left counter;
            }
                
        }
        
        
        
        return ans;
        
    }
};