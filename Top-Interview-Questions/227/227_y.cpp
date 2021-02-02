class Solution {
public:
    int calculate(string s) {
     
      // stack<int> st;
        if(s.size()==0)
            return 0;
        int last  = 0;
        int curr = 0;
        char op = '+';
        int sum = 0;
        
        for(int i =0; i<s.size(); i++){
        
            if(s[i]>='0' && s[i]<='9'){
                curr = curr*10 + (s[i] -'0');
            }
            
            if(s[i]!=' ' && !(s[i]>='0' && s[i]<='9') || i == s.size()-1 ){
                if(op=='+'){
                    sum+= last;
                    last = curr;
                }   
                if(op =='-'){
                    sum+= last;
                    last = -curr;
                }
                if(op == '*'){
                    last *= curr;
                }
                if(op == '/'){
                    last/= curr;
                }
                
                curr = 0;
                op = s[i];               
                
            }
            
            
        }
        sum+= last;
        return sum;
    }
};