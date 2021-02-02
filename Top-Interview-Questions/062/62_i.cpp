class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> hori(n,1);
        int vert=1;
        for(int i=1;i<m;i++){
            vert=1;
            for(int j=1;j<n;j++){
                vert=hori[j]+vert;
                hori[j]=vert;
            }
        }
        return vert;
    }
};
