class Solution {
public:
    bool isPalindrome(string s) {
        
        int n = s.size();
        int l =0,r = n-1;
        
        while(l<=r){
            
            while(l<n &&(!isalnum(s[l])))
                l++;
            while( r>=0 && (!isalnum(s[r])))
                r--;
            
            if(l>r)
                break;
            
            if(tolower(s[l])!=tolower(s[r]))
                return false;
            
            l++;
            r--;
            
            
        }
        
        return true;
        
    }
};