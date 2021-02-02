class Solution {
public:
    
    bool dfs(vector<int>adj[],vector<bool>&visited,vector<bool>&rec,int node){
        
    visited[node]=true;
    rec[node]=true;
        
    for(auto it : adj[node] )
    {
        if(rec[it]){
            return true;
        }
        else if(!visited[it] && dfs(adj,visited,rec,it))
        {
            return true;
        }
    }
    rec[node]=false;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        
        vector<int>adj[numCourses];
        for(auto it:pre)
        {
            adj[it[0]].push_back(it[1]);
        }
        vector<bool>visited(numCourses,false);
        vector<bool>rec(numCourses,false);
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(dfs(adj,visited,rec,i))
                {
                    return false;
                }
            }
        }
        return true;
        
        
    }
};