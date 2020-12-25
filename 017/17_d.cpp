class Solution {
public:
    void recursion(string dig, int pos, string temp, vector<string> &ans)
    {
        if(pos==dig.length())
        {
            ans.push_back(temp);
            return;
        }
        string options;
        switch(dig[pos])
        {
            case '2': options = "abc"; break;
            case '3': options = "def"; break;
            case '4': options = "ghi"; break;
            case '5': options = "jkl"; break;
            case '6': options = "mno"; break;
            case '7': options = "pqrs"; break;
            case '8': options = "tuv"; break;
            case '9': options = "wxyz"; break;
            default: options = ""; break;
        }
        for(int i=0;i<options.length();i++)
            recursion(dig, pos+1, temp+options[i], ans);
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0)
            return ans;
        recursion(digits, 0, "", ans);
        return ans;
    }
};