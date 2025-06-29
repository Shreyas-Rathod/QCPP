class Disjoint {
    vector<int> parent, rnk;
public:
    Disjoint(int n) : parent(n), rnk(n, 0) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    
    int findPar(int x) {
        return parent[x] == x
            ? x
            : parent[x] = findPar(parent[x]);
    }
    
    void unionByRank(int x, int y) {
        int rx = findPar(x), ry = findPar(y);
        if (rx == ry) return;
        if (rnk[rx] > rnk[ry]) {
            parent[ry] = rx;
        } else if (rnk[rx] < rnk[ry]) {
            parent[rx] = ry;
        } else {
            parent[ry] = rx;
            rnk[rx]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint ds(n);
        unordered_map<string,int> owner;  // email → first account index seen
        
        // 1) Union accounts by the same email
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                const string &em = accounts[i][j];
                if (owner.count(em)) {
                    ds.unionByRank(i, owner[em]);
                } else {
                    owner[em] = i;
                }
            }
        }
        
        // 2) Gather emails under each root
        unordered_map<int, vector<string>> groups;  
        for (auto &p : owner) {
            int root = ds.findPar(p.second);
            groups[root].push_back(p.first);
        }
        
        // 3) Build the answer
        vector<vector<string>> res;
        for (auto &g : groups) {
            auto &emails = g.second;
            sort(emails.begin(), emails.end());
            vector<string> merged;
            merged.push_back(accounts[g.first][0]);        // account name
            merged.insert(merged.end(), emails.begin(), emails.end());
            res.push_back(move(merged));
        }
        
        return res;
    }
};
