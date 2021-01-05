class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       
        int right = nums1.size()-1;
        int w1 = m-1;
        int w2 = n-1;
        
        if(n==0)
            return;
        
        if(m==0){
            while(right>=0){
                nums1[right]=nums2[w2];
                right--;
                w2--;
            }            
            return;
        }
        
        
        
        
        
        while(right>=0 && w1>=0 && w2 >=0){
            
            if(nums2[w2]>nums1[w1]){
                nums1[right]=nums2[w2];
                
                w2--;
                right--;
            }
            else{
                nums1[right]=nums1[w1];
                w1--;
                right--;
            }
            
        }
        
        while(w2>=0){
            nums1[right]=nums2[w2];
            w2--;
            right--;
        }
        
       return;
    }
};