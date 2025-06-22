class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9+7;
        // build adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for (auto &r : roads) {
            int u = r[0], v = r[1], w = r[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        // dist[] may exceed INT_MAX, so use long long and initialize to LLONG_MAX
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        // min-heap of (current_distance, node)
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0LL, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) 
                continue;    // stale entry

            for (auto &edge : adj[u]) {
                int v = edge.first;
                long long w = edge.second;
                long long nd = d + w;

                // found a strictly shorter path to v
                if (nd < dist[v]) {
                    dist[v] = nd;
                    ways[v] = ways[u];
                    pq.push({nd, v});
                }
                // found an additional shortest path of the same length
                else if (nd == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n-1];
    }
};
