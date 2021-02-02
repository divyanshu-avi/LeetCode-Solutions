class Solution {
public:
    void func(int i, int len, vector<string> &ans, string temp, map<char, string> m, string digits){
        if(i==digits.length() && temp.length()!=0){
            ans.push_back(temp);
        }
        for(int j=0;j<m[digits[i]].length();j++){
            temp[i]=m[digits[i]][j];
            func(i+1, len, ans, temp, m, digits);
        }
    }
    vector<string> letterCombinations(string digits) {
        
        
        
        int len=digits.length(), i=0;
        vector<string> ans;
        string temp(len, '*');
        map <char, string> m;
        m.insert({'2',"abc"});
        m.insert({'3', "def"});
        m.insert({'4', "ghi"});
        m.insert({'5', "jkl"});
        m.insert({'6', "mno"});
        m.insert({'7', "pqrs"});
        m.insert({'8', "tuv"});
        m.insert({'9', "wxyz"});
        func(i, len, ans, temp, m, digits);
        return ans;
    }
};
