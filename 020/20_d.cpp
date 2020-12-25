class Solution {
public:
    bool isValid(string s) {
        int i;
        stack<char> st;
        char ulta;
        for(i=0;i<s.length();i++)
        {
            switch(s[i])
            {
                case ')' : ulta = '('; break;
                case ']' : ulta = '['; break;
                case '}' : ulta = '{'; break;
                default : ulta = 0;
            }
            if(ulta)
            {
                if(st.empty() || st.top() != ulta)
                    return false;
                st.pop();
            }
            else
                st.push(s[i]);
        }
        return st.empty();
    }
};