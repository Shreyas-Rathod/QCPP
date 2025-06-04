class Solution {
public:
    int bfs(vector<vector<int>>&cities, int V, vector<bool>&vis, int root){
        queue<int>q;
        q.push(root);
        vis[root] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i = 0;i<V;i++){
                if(!vis[i] && cities[node][i]){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
        return 1;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size(), count = 0;
        vector<bool>vis(V, false);
        for(int i = 0;i<V;i++){
            if(!vis[i]) count += bfs(isConnected, V, vis, i);
        }
        return count;
    }
};