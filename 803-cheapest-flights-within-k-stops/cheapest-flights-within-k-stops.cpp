class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int, pair<int, int>>>pq;
        vector<vector<pair<int, int>>>adj(n);
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;

        for(int i = 0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        pq.push({0, {0, src}});
        while(!pq.empty()){
            auto node = pq.front();
            int kt = node.first, wt = node.second.first, u = node.second.second;
            pq.pop();
            for(auto &it : adj[u]){
                if(dist[it.first] > wt + it.second && kt <= k){
                    dist[it.first] = wt + it.second;
                    pq.push({kt+1, {wt + it.second, it.first}});
                }
            }  
        }

        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};