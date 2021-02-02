class Solution {
public:
    string fractionToDecimal(int num, int d) {
        
        string s;
        
        int sign = 0;
        sign = (num<0 && d>0) || (num>0 && d<0)? 1:0;
        long long int n = abs((long long int)num);
        d = abs(d);
        
        if(sign)
            s = "-";
        
        s += to_string(n/d);
        n = n%d;
        
        if(n==0)
            return s;
        
        
        map<int,int> mp;
        int i = s.size()+1;
        
        
        s = s+".";
        
        while(n){
            
            if(mp.find(n)!=mp.end()){
                
                s.insert(mp[n],"(");
                s.push_back(')');
                    return s;
                
                
            }else{
                mp[n]=i;
                i++;
            }
        
            s += to_string((long int)n*10/(long long int)d);
            
            n = ((long long int)n*10)%d;
            
            
        }
        
        
        return s;
    }
};