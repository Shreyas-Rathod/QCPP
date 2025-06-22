class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<vector<pair<int, long long>>>adj(n);
        int m = roads.size();
        for(int i = 0;i<m;i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<int>ways(n, 0);
        ways[0] = 1;
        dist[0] = 0;
        set<pair<long long, int>>pq;
        pq.insert({dist[0], 0});

        while(!pq.empty()){
            auto [wt, u] = *pq.begin();
            pq.erase(pq.begin());
            if(u == n-1) break;
            if(wt > dist[u]) continue;
            for(auto &it : adj[u]){
                if(dist[it.first] > wt + it.second){
                    dist[it.first] = wt + it.second;
                    ways[it.first] = ways[u];
                    pq.insert({dist[it.first], it.first});
                }
                else if(dist[it.first] == wt + it.second){
                    ways[it.first] = (ways[u] + ways[it.first])%mod;
                }
            }
        }

        return ways[n-1];
    }
};