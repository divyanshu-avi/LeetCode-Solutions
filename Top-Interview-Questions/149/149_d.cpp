class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1, dup, i, j, gcd, num, den, max_count, n = points.size();
        unordered_map<string, int> line;
        
        if(!n) return 0;
        
        for(i=0;i<n-1;i++)
        {
            dup = 1;
            line.clear();
            max_count = 0;
            for(j=i+1;j<n;j++)
            {
                if(points[i] == points[j])
                {
                    dup++;
                    continue;
                }
                else
                {
                    num = points[j][0] - points[i][0];
                    den = points[j][1] - points[i][1];
                    gcd = __gcd(num, den);
                    num = num/gcd; den = den/gcd;
                    string temp = to_string(num) + "/" + to_string(den);
                    line[temp]++;
                    max_count = max(max_count, line[temp]);
                }
            }
            ans = max(ans, max_count + dup);
        }
        return ans;
    }
};