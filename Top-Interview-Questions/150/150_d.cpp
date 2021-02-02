class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int temp;
        for(int i=0 ; i<tokens.size() ; i++)
        {
            if(tokens[i] == "+")
            {
                temp = st.top();
                st.pop();
                temp = st.top() + temp;
                st.pop();
                st.push(temp);
            }
            else if(tokens[i] == "-")
            {
                temp = st.top();
                st.pop();
                temp = st.top() - temp;
                st.pop();
                st.push(temp);
            }
            else if(tokens[i] == "*")
            {
                temp = st.top();
                st.pop();
                temp = st.top() * temp;
                st.pop();
                st.push(temp);
            }
            else if(tokens[i] == "/")
            {
                temp = st.top();
                st.pop();
                temp = st.top() / temp;
                st.pop();
                st.push(temp);
            }
            else
                st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};