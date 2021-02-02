class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1)//Base cases
            return 1;
        int i, cur=1, prev = 1, temp;
        while(n-- >= 2)
        {
            temp = cur;
            cur = cur + prev;
            prev = temp;
        }
        //Using the recurrence relation climb(n) = climb(n-1) + climb(n-2)
        return cur;
    }
};