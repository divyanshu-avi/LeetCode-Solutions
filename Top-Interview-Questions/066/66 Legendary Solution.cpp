class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i;
        for(i=digits.size()-1; i>=0; i--)
        {
            if(digits[i] == 9)
                digits[i] = 0;
            else
            {
                digits[i]++;
                return digits;;
            }
        }
        //if we reached here means the num is 9999...
        digits.push_back(0);
        digits[0]=1;
        return digits;
    }
};