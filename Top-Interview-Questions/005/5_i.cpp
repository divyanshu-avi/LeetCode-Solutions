class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        ans.push_back(s[0]);
        for(int i=0;i<s.length();i++){
            int j=1, len=1;
            while(i-j>=0 && i+j<s.length() && s[i-j]==s[i+j]){
                len+=2;
                j++;
            }
            if(ans.length()<len){
                ans=s.substr(i-j+1,len);
            }
            j=0, len=0;
            while(i-j>=0 && i+j<s.length() && s[i-j]==s[i+1+j]){
                j++;
                len+=2;
            }
            if(ans.length()<len){
                ans=s.substr(i-j+1, len);
                //cout<<ans;
            }
        }
        return ans;
    }
};
