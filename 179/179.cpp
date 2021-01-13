class Solution {
public:
    
    static bool compi(int a, int b){
        
        string temp1 = to_string(a);
        string temp2 = to_string(b);
        
        return (temp1+temp2)>(temp2+temp1);
       
    }
    
    string largestNumber(vector<int>& nums) {
     
        string s;
        sort(nums.begin(),nums.end(),compi);
        
        if(nums[0]==0)
            return "0";
        
        for(int i =0; i<nums.size(); i++){
            s+=to_string(nums[i]);
        }
        
        
        return s;
    }
    

    
};