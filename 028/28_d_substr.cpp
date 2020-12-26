class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        int i, j, m = haystack.length(), n = needle.length();
        for(i=0;i<=m-n;i++)
            if(haystack[i] == needle[0] && i+n-1<m && haystack.substr(i,n)==needle)
                return i;
        return -1;
    }
};