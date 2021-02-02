class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        
        unordered_map<string,int>mp;
        mp["/"]=0;
        mp["+"]=1;
        mp["-"]=2;
        mp["*"]=3;
        int a,b,n;
        int ans;
        
        int i = 0;
        
        while(i<tokens.size()){
            
            if(mp.find(tokens[i])==mp.end()){
                n = stoi(tokens[i]);
                st.push(n);
                i++;
            }else{
                
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                
                switch(mp[tokens[i]]){
                    case 0: a = a/b;break;
                    case 1: a = a+b;break;
                    case 2: a = a-b;break;
                    case 3: a = a*b;break;
                }
                
                st.push(a);
                i++;
            }
            
            
        }
        
        
        return st.top();
    }
};