class Solution {
public:
    int myAtoi(string s) {
        string a;
        int ans=0, flag=0, j=0;
        while(s[j]==' '){
            j++;
        }
        a=s.substr(j);
        if(a.substr(0, 11)=="-2147483648" || a.substr(0,11)=="-2147483649"){
            return INT_MIN;
        }
        else if(a.substr(0,11)=="2147483648" || a.substr(0,11)=="2147483649"){
            return INT_MAX;
        }
        int i=0;
        if(a[i]=='-'){
            flag=1;
            i++;
        }
        else if(a[i]=='+'){
            flag=0;
            i++;
        }
        else if(a[0]<'0' || a[0]>'9'){
            return 0;
        }
        while(a[i]>='0' && a[i]<='9'){
            if(i==a.length()){
                break;
            }
            if(INT_MAX/10<ans){
                if(flag==1){
                    return INT_MIN;
                }
                else if(flag==0){
                    return INT_MAX;
                }
            }
            ans*=10;
            ans+=(a[i]-'0');
            i++;
        }
        if(flag==1){
            ans*=-1;
        }
        return ans;
    }
};
