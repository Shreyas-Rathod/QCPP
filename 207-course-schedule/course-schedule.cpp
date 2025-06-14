class Solution {
public:
    bool dfs(int node, vector<bool>&vis, vector<vector<int>>& adj, int V, vector<bool>&path){
        vis[node] = true;
        path[node] = true;
        for(int &it : adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, adj, V, path)) return true;
            }
            else if(path[it]) return true;
        }
        path[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<bool>vis(numCourses, false), path(numCourses, false);
        int n = prerequisites.size();
        for(int i = 0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i = 0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i, vis, adj, numCourses, path)) return false;
            }
        }
        return true;
    }
};