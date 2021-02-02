class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            string s="";
            return s;
        }
        string s=strs[0];
        int len=s.length();
        for(int i=1;i<strs.size();i++){
            string temp=strs[i];
            int stlen=temp.length();
            while(s!=temp && len>0){
                if(len>stlen){
                    len--;
                    s=s.substr(0,len);
                }
                else{
                    stlen--;
                    temp=temp.substr(0,stlen);
                }
            }
        }
        return s;
    }
};
