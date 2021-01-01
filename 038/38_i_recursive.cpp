class Solution {
public:
    void func(int i, int n, string &ans, string temp, string backup){
        if(i>=n){
            ans=temp;
            return;
        }
        backup="";
        int count=1, j;
        for(j=0;j<temp.length()-1;j++){
            if(temp[j]==temp[j+1]){
                count++;
            }
            else{
                backup.push_back((char)(count+48));
                backup.push_back(temp[j]);
                count=1;
            }
        }
        backup.push_back((char)(count+48));
        backup.push_back(temp[j]);
        temp=backup;
        func(i+1, n, ans, temp, backup);
        return ;
    }
    
    string countAndSay(int n) {
        int i=1;
        string ans="", temp="1", backup;
        func(i, n, ans, temp, backup);
        return ans;
    }
};
