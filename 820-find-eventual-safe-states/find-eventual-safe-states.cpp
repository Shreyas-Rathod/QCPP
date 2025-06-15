class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>>adj(V);
        vector<int>indegree(V, 0);
        for(int i = 0;i<V;i++){
            for(int &it : graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        vector<int>safeNode;
        queue<int>q;
        for(int i = 0;i<V;i++){
            if(!indegree[i]) q.push(i);
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            safeNode.push_back(u);
            for(int &it : adj[u]){
                indegree[it]--;
                if(!indegree[it]) q.push(it);
            }
        }
        sort(safeNode.begin(), safeNode.end());
        return safeNode;
    }
};