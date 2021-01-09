class Solution {
public:
    bool isPalindrome(int start, int end, string& s)
    {
        while(start<end)
        {
            if(s[start] != s[end])
                break;
            start++; end--;
        }
        return start>=end;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp1, temp2;
        string temp = "";
        int i, j;
        if(!s.length())
            return ans;
        for(i=0; i<s.length();i++)
        {
            if(isPalindrome(0, i, s))
            {
                vector<vector<string>> suffix = partition(s.substr(i+1));
                temp1.clear();
                temp1.push_back(s.substr(0, i+1));
                for(j=0;j<suffix.size();j++)
                {
                    temp2 = temp1;
                    temp2.insert(temp2.end(), suffix[j].begin(), suffix[j].end());
                    ans.push_back(temp2);
                }
                if(j==0)
                    ans.push_back(temp1);
            }
        }
        return ans;
    }
};