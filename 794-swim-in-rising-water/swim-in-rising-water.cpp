class Disjoint{
    vector<int>rank, par;
    public : 
        Disjoint(int n){
            rank.resize(n+1, 0);
            par.resize(n+1);
            for(int i = 0;i<=n;i++){
                par[i] = i;
            }
        }

        int findp(int x){
            if(par[x] == x) return x;
            return par[x] = findp(par[x]);
        }

        void unionbyRank(int x, int z){
            int parx = findp(x);
            int parz = findp(z);

            if(parx == parz) return;
            if(rank[parx] > rank[parz]) par[parz] = parx;
            else if(rank[parx] < rank[parz]) par[parx] = parz;
            else{
                par[parx] = parz;
                rank[parx]++;            
            }
        }
};

class Solution {
private:
    bool isvalid(int i, int j, int n, vector<vector<bool>>&vis){
        return i >= 0 && j >= 0 && i < n && j < n && vis[i][j];
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>>vis(n, vector<bool>(n, false));

        vector<pair<int, pair<int, int>>>mat;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                mat.push_back({grid[i][j], {i, j}});
            }
        }

        Disjoint ds(n*n);
        sort(mat.begin(), mat.end());
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for(auto it : mat){
            int row = it.second.first;
            int col = it.second.second;
            int curr = row * n + col;
            vis[row][col] = true;

            for(int i = 0;i<4;i++){
                int r = row + dx[i];
                int c = col + dy[i];

                if(isvalid(r, c, n, vis)){ 
                    int adj = r * n + c;
                    ds.unionbyRank(curr, adj);
                }
            }

            if(ds.findp(n*n - 1) == ds.findp(0)) return it.first;

        }

        return -1;
    }
};