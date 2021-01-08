class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length(), i, j;
        if(!n)
            return true;
        i=0; j = n-1;
        while(i<j)
        {
            if(!isalnum(s[i]))
            {
                i++;
                continue;
            }
            if(!isalnum(s[j]))
            {
                j--;
                continue;
            }
            if(toupper(s[i]) != toupper(s[j]))
                break;
            i++; j--;
        }
        return i>=j;
    }
};