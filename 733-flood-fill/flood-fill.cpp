class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int m = grid.size(), n = grid[0].size(), tc = 0, cc = 0;
        queue<pair<int, int>>q;
        q.push({sr, sc});
        cc++;
        tc = grid[sr][sc];
        while(!q.empty()){
            int currCount = cc;
            cc = 0;        
            while(currCount--) {
                auto [r, c] = q.front();
                q.pop();
                grid[r][c] = -1;   
                
                if(r-1 >= 0 && grid[r-1][c] == tc) {
                    grid[r-1][c] = -1;
                    q.push({r-1, c});
                    cc++;
                }
                if(c+1 < n && grid[r][c+1] == tc) {
                    grid[r][c+1] = -1;
                    q.push({r, c+1});
                    cc++;
                }
                if(r+1 < m && grid[r+1][c] == tc) {
                    grid[r+1][c] = -1;
                    q.push({r+1, c});
                    cc++;
                }
                if(c-1 >= 0 && grid[r][c-1] == tc) {
                    grid[r][c-1] = -1;
                    q.push({r, c-1});
                    cc++;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == -1)  grid[i][j] = color;
            }
        }
        return grid;
    }
};