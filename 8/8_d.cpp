class Solution {
public:
    int myAtoi(string s) {
        long long int ans = 0;
        int sign = 1, i;
        for(i=0;i<s.length();i++)
        {
            if(s[i] == '-')
                sign = -1;
            if(s[i] == ' ')
                continue;
            else//could be a digit or not a digit, we'll check later
                break;
        }
        if(s[i] == '-' || s[i] == '+')
            i++;
        for(;i<s.length();i++)
        {
            if(!isdigit(s[i]))
                break;
            ans = ans*10 + (s[i] - '0');
            if(ans*sign > INT_MAX)
                return INT_MAX;
            if(ans*sign < INT_MIN)
                return INT_MIN;
        }
        return ans*sign;
    }
};