class Solution {
public:
    string countAndSay(int n) {
        string ans = "1", temp = "";
        int i, count=1;
        if(n==1)
            return ans;
        while(n-- > 1)
        {
            for(i=0;i<ans.length();i++)
            {
                if(i<ans.length()-1 && ans[i] == ans[i+1])
                    count++;
                else
                {
                    temp += ('0' + count);
                    temp += ans[i];
                    count = 1;
                }
            }
            ans = temp;
            temp = "";
        }
        return ans;
    }
};