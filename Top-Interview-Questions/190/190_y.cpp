class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        queue<int> q;
        uint32_t ans=00000000000000000000000000000000;
        for(int i =0; i<32; i++){
            ans = ans<<1;
            ans |= n&1;
            n = n>>1;
            
        }
        
        return ans;
        
    }
};class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        queue<int> q;
        uint32_t ans=00000000000000000000000000000000;
        for(int i =0; i<32; i++){
            ans = ans<<1;
            ans |= n&1;
            n = n>>1;
            
        }
        
        return ans;
        
    }
};