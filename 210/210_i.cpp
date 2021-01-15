class Solution {
public:
    bool cycle(vector<vector<int>> &mat, int numCourses){
        vector<int> visited(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                bool flag=dfs(mat, visited, i);
                if(flag==1)
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<int>> &mat, vector<int>&visited, int i){
        visited[i]=2;
        for(int j=0;j<mat[i].size();j++){
            if(visited[mat[i][j]]==1)
                continue;
            else if(visited[mat[i][j]]==2)
                return true;
            else{
                if(dfs(mat, visited, mat[i][j]))
                    return true;
            }
        }
        visited[i]=1;
        return false;
    }
    
    void topo(vector<vector<int>>&mat, vector<int>&visited, int i, stack<int> &s){
        visited[i]=1;
        for(int j=0;j<mat[i].size();j++){
            if(visited[mat[i][j]]==0){
                topo(mat, visited, mat[i][j], s);
            }
        }
        s.push(i);
        return ;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> mat(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            mat[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //detect cycle
        if(cycle(mat, numCourses))
            return {};
        //topological sort
        stack<int> s;
        vector<int> visited(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0)
                topo(mat, visited, i, s);
        }
        // pop from stck to ans
        vector<int> ans;
        while(!s.empty()){
            int temp=s.top();
            s.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};
