class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> index;
        string temp;
        int i;
        for(i=0;i<strs.size();i++)
        {
            temp = strs[i];
            sort(temp.begin(), temp.end());
            if(index.find(temp) != index.end())//If encountered before
                ans[index[temp]].push_back(strs[i]);
            else
            {
                index[temp] = ans.size();
                ans.push_back(vector<string>(1, strs[i]));
            }
        }
        return ans;
    }
};