class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26, 0);
        int i, n = s.length();
        for (i = 0; i < n; i++)
            count[s[i] - 'a']++;
        for (i = 0; i < n; i++)
            if (count[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};