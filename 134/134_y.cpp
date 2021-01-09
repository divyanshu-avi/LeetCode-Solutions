class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        
        long long int sum =0;
        
        for(int i =0; i<n; i++){
            
            gas[i]= gas[i]-cost[i];
            sum+= gas[i];
        }
    
        if(sum<0)
            return -1;
       
        int index = -1;
        int s =0;
        
        for(int i =0; i<n; i++){
            
            s += gas[i];
            
            if(index == -1 && gas[i]>=0){
                index =i;
            }else if(s<0 && gas[i]<0){
                index = -1;
                s =0;
                
            }
            
        }
        return index;
        
    }
};