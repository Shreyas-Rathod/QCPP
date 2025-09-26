class Solution {
public:
    bool dfs(int node, vector<bool>&vis, vector<bool>&safe, vector<bool>&path, vector<vector<int>>&adj){
        vis[node] = true;
        safe[node] = false;
        path[node] = true;

        for(int &it : adj[node]){
            if(!vis[it]){
                if(dfs(it, vis, safe, path, adj)){
                    safe[node] = false;
                    return true;
                }
            }
            else if(path[it]){
                safe[node] = false;
                return true;
            }
        }

        path[node] = false;
        safe[node] = true;

        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool>vis(V, 0), safe(V, 0), path(V, 0);
        vector<int>res;

        for(int i = 0;i<V;i++){
            if(!vis[i]) dfs(i, vis, safe, path, graph);
        }

        for(int i = 0;i<V;i++){
            if(safe[i]) res.push_back(i);
        }

        return res;
    }
};