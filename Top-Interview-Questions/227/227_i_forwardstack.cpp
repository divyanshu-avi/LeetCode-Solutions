class Solution {
public:
    //using stack
    int calculate(string s) {
        stack<int> st;
        char prevop='+';
        int ans=0, num=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ') continue;
            if(isdigit(s[i])){
                num*=10;
                num+=s[i]-'0';
            }
            else{
                if(prevop=='+'){
                    st.push(num);
                }
                else if(prevop=='-'){
                    num*=-1;
                    st.push(num);
                }
                else if(prevop=='*'){
                    num*=st.top();
                    st.pop();
                    st.push(num);
                }
                else if(prevop=='/'){
                    num=st.top()/num;
                    st.pop();
                    st.push(num);
                }
                num=0;
                prevop=s[i];
            }
        }
        if(prevop=='+'){
            st.push(num);
        }
        else if(prevop=='-'){
            num*=-1;
            st.push(num);
        }
        else if(prevop=='*'){
            num*=st.top();
            st.pop();
            st.push(num);
        }
        else if(prevop=='/'){
            num=st.top()/num;
            st.pop();
            st.push(num);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
