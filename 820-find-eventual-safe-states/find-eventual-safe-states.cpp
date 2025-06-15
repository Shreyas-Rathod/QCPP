class Solution {
public:
    bool dfs(int node, vector<vector<int>>&adj, vector<bool>&vis, vector<bool>&path, vector<bool>&check){
        vis[node] = true;
        path[node] = true;
        check[node] = false;
        for(int &it : adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, path, check)){
                    check[node] = false;
                    return true;
                }
            }
            else if(path[it]){
                check[node] = false;
                return true;
            }
        }
        path[node] = false;
        check[node] = true;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool>vis(V, false), path(V, false), check(V, false);
        vector<int>safeNode;
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                dfs(i, graph, vis, path, check);
            }
        }
        for(int i = 0;i<V;i++){
            if(check[i]) safeNode.push_back(i);
        }
        return safeNode;
    }
};