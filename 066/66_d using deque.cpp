class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1, sum, i;
        deque<int> dq;
        for(i=digits.size()-1; i>=0; i--)
        {
            sum = digits[i] + carry;
            dq.push_front(sum%10);
            carry = sum/10;
        }
        if(carry)
            dq.push_front(carry);
        return {dq.begin(), dq.end()};
    }
};