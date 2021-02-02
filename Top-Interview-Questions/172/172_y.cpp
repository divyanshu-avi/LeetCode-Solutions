
class Solution {
public:
    int trailingZeroes(int n) {
        
        int count = 0;
        int div = 5;
        
        while((n/div)>0){
            count+= n/div;
            div = div*5; 
            
        }
       
            
        return count;
    }
};