class Solution {
public:
    bool dfs(int node, vector<vector<int>>&graph, int rang, vector<int>&color){
        color[node] = !rang;
        for(int i = 0;i<graph[node].size();i++){
            if(graph[node][i]){
                if(color[graph[node][i]] == -1){
                    if(!dfs(graph[node][i], graph, color[node], color)) return false;
                }
                else if(color[graph[node][i]] == color[node]) return false;
            }
            else continue;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>color(V, -1);
        for(int i = 0;i<V;i++){
            if(color[i] == -1){
                if(!dfs(i, graph, 1, color)) return false;
            }
        }
        return true;
    }
};