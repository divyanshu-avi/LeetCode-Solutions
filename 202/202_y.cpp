class Solution {
public:
    
    bool isHappy(int n) {
        
      if(n==1)
          return true;
        
        unordered_set<int> mp;
        int sum = 0;
        
        while(sum!=1){
            
            if(mp.find(sum)!=mp.end())
                return false;
            
            mp.insert(sum);
            sum = 0;
            while(n){
                sum += pow((n%10),2);
                n = n/10;
            }
            
            n = sum;
            cout<<n<<endl;
        }
        
        return true;
    }
};