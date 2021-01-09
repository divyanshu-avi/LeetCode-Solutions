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
    
    void recur(string s, int partition, vector<string>& temp, vector<vector<string>>& ans)
    {
        if(partition == s.length())
        {
            ans.push_back(temp);
            return;
        }
        int i;
        for(i=partition ; i<s.length() ; i++)
        {
            if(isPalindrome(partition, i, s))
            {
                temp.push_back(s.substr(partition, i-partition+1));
                recur(s, i+1, temp, ans);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        recur(s, 0, temp, ans);
        
        return ans;
    }
};