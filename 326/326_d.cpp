class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && pow(3, ceil(log(n)/log(3)))==n;
    }
};