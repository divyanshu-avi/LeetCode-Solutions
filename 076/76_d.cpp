class Solution {
public:
    string minWindow(string s, string t) {
        //unordered_map<char, int> count, req;
        vector<int> count(123, 0), req(123,0);
        int i, start ,end, n = s.length(), satisfied = 0, minlen=INT_MAX, requirement=0;
        string ans = "";
        bool belongs;
        for(i=0;i<t.length();i++)//Store counts of each character in the map
        {
            req[t[i]]++;
            if(req[t[i]] == 1)
                requirement++;
        }
        start = 0; end = 0;
        while(start<n && end<=n)
        {
            if(satisfied == requirement)
            {
                if(end-start < minlen)
                {
                    ans = s.substr(start, end-start);
                    minlen = end-start;
                }
                if(req[s[start]] != 0)
                {
                    count[s[start]]--;
                    if(count[s[start]] < req[s[start]])//If count < required then that character is unsatisfied
                        satisfied--;
                }
                start++;
                continue;
            }
            if(end<n &&req[s[end]] != 0)//If current char belongs to t
            {
                count[s[end]]++;
                if(count[s[end]] == req[s[end]])
                    satisfied++;
            }
            end++;
        }
        return ans;
    }
};