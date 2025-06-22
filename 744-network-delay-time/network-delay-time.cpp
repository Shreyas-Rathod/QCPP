class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dis(n, INT_MAX);
        dis[k-1] = 0;
        int m = times.size();
        vector<vector<pair<int, int>>>adj(n);
        for(int i = 0;i<m;i++){
            adj[times[i][0]-1].push_back({times[i][1]-1, times[i][2]});
        }
        set<pair<int, int>>pq;
        pq.insert({0, k-1});
        while(!pq.empty()){
            auto [wt, u] = *pq.begin();
            pq.erase(pq.begin());
            for(auto &it : adj[u]){
                if(dis[it.first] > wt + it.second){
                    dis[it.first] = wt + it.second;
                    pq.insert({dis[it.first], it.first});
                }
            }
        }
        int res = *max_element(dis.begin(), dis.end());
        if(res == INT_MAX) return -1;
        return res;
    }
};