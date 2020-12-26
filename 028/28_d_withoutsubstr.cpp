class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        int i, j, m = haystack.length(), n = needle.length();
        for(i=0;i<=m-n;i++)
        {
            if(haystack[i] == needle[0])
            {
                j=0;
                while(j<n && i+j<m && needle[j]==haystack[i+j])
                    j++;
                if(j==n)
                    return i;
                    
            }
        }
        return -1;
    }
};