class Solution {
private:
    int timer = 1;
    void dfs(int node, int par, int tin[], int low[], vector<vector<int>>&adj, vector<bool>&vis, vector<vector<int>>&bridges){
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;

        for(auto it : adj[node]){
            if(it == par) continue;
            if(!vis[it]){
                dfs(it, node, tin, low, adj, vis, bridges);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]) bridges.push_back({it, node});
            }
            else{
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        int m = connections.size();
        for(int i = 0;i<m;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int tin[n];
        int low[n];
        vector<vector<int>>bridges;
        vector<bool>vis(n, false);
        dfs(0, -1, tin, low, adj, vis, bridges);
        return bridges;
    }
};