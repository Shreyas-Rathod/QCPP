class Disjoint{
    vector<int>rank, par;
    public:
    Disjoint(int n){
        rank.resize(n+1);
        par.resize(n+1, 0);
        for(int i = 0;i<=n;i++) par[i] = i;
    }

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unionbyRank(int x, int z){
        int xpar = find(x);
        int zpar = find(z);
        if(xpar == zpar) return;
        if(rank[xpar] < rank[zpar]) par[xpar] = zpar;
        else if(rank[xpar] > rank[zpar]) par[zpar] = xpar;
        else{
            par[zpar] = xpar;
            rank[zpar]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxR = 0;
        int maxC = 0;
        for(auto it : stones){
            maxR = max(maxR, it[0]);
            maxC = max(maxC, it[1]);
        }

        Disjoint ds(maxR + maxC + 1);
        unordered_map<int, int> nodes;
        for(auto it : stones){
            int nr = it[0];
            int nc = it[1] + maxR + 1;
            ds.unionbyRank(nr, nc);
            nodes[nr] = 1;
            nodes[nc] = 1;
        }

        int cnt = 0;
        for(auto it : nodes){
            if(ds.find(it.first) == it.first) cnt++;
        }

        return n - cnt;
    }
};