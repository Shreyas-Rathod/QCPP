class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
private:
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        // step - 1
        for (int row = 0; row < n ; row++) {
            for (int col = 0; col < n ; col++) {
                if (grid[row][col] == 0) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        // step 2
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n)) {
                        if (grid[newr][newc] == 1) {
                            components.insert(ds.findUPar(newr * n + newc));
                        }
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        return mx;
    }
};
/*

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>>vis(n, vector<bool>(n, false));
        stack<pair<int, int>>st;
        map<int, int>mp;
        int cnt = 0;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] && !vis[i][j]){
                    st.push({i, j});
                    int area = 0;
                    cnt++;
                    while(!st.empty()){
                        int r = st.top().first;
                        int c = st.top().second;
                        area++;
                        vis[r][c] = true;
                        grid[r][c] = cnt;
                        st.pop();

                        if(r+1 < n && !vis[r+1][c] && grid[r+1][c]){
                            vis[r+1][c] = true;
                            st.push({r+1, c});
                        } 
                        if(c+1 < n && !vis[r][c+1] && grid[r][c+1]){
                            vis[r][c+1] = true;
                            st.push({r, c+1});
                        }
                        if(r-1 >= 0 && !vis[r-1][c] && grid[r-1][c]){
                            vis[r-1][c] = true;
                            st.push({r-1, c});
                        }
                        if(c-1 >= 0 && !vis[r][c-1] && grid[r][c-1]){
                            vis[r][c-1] = true;
                            st.push({r, c-1});
                        }
                    }
                    mp[cnt] = area;
                }
            }
        }

        if(mp.size() == 0) return 1;
        
        int res = 1;
        bool flag = false;
        for(int r = 0;r<n;r++){
            for(int c = 0;c<n;c++){
                if(!grid[r][c]){
                    flag = true;
                    int temparea = 1;
                    unordered_set<int> seen;
                    if (r+1 < n && grid[r+1][c] && seen.insert(grid[r+1][c]).second)
                        temparea += mp[ grid[r+1][c] ];
                    if (c+1 < n && grid[r][c+1] && seen.insert(grid[r][c+1]).second)
                        temparea += mp[ grid[r][c+1] ];
                    if (r-1 >= 0 && grid[r-1][c] && seen.insert(grid[r-1][c]).second)
                        temparea += mp[ grid[r-1][c] ];
                    if (c-1 >= 0 && grid[r][c-1] && seen.insert(grid[r][c-1]).second)
                        temparea += mp[ grid[r][c-1] ];
                    res = max(res, temparea);
                }
            }
        }

        if(!flag) return n*n;
        return res;
    }
};

*/