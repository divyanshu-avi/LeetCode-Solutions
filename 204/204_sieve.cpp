class Solution {
public:
    int countPrimes(int n) {
        
        if(n==0 || n==1 || n==2)
            return 0;
    
        vector<int> a(n,1);
        a[0]= 0;
        a[1] = 0;
        a[2] = 1;
        
        for(int i =1; i<n; i++){
        
            if(a[i]==1){      
                int  j = i+i; 
                while(j<n){
                    a[j] = 0;
                    j += i;
                }   
            }
        }
        int count = 0;
        for(int i=0 ; i<n; i++)
        if(a[i]==1)
            count++;
        
        return count;
    }
};