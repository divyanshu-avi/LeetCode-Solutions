class Solution {
public:
    //using stack
    int calculate(string s) {
        char prevop='+';
        int ans=0, num=0, prev=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ') continue;
            if(isdigit(s[i])){
                num*=10;
                num+=s[i]-'0';
            }
            else{
                if(prevop=='+' || prevop=='-')
                    ans+=prev;
                if(prevop=='+'){
                    prev=num;
                }
                else if(prevop=='-'){
                    num*=-1;
                    prev=num;
                }
                else if(prevop=='*'){
                    prev=prev*num;
                }
                else if(prevop=='/'){
                    prev=prev/num;
                }
                num=0;
                prevop=s[i];
            }
        }
        if(prevop=='+' || prevop=='-')
            ans+=prev;
        if(prevop=='+'){
            prev=num;
        }
        else if(prevop=='-'){
            num*=-1;
            prev=num;
        }
        else if(prevop=='*'){
            prev=prev*num;
        }
        else if(prevop=='/'){
            prev=prev/num;
        }
        ans+=prev;
        return ans;
    }
};
