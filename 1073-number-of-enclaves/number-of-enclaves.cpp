class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        stack<pair<int, int>>st;
        st.push({i, j});
        while(!st.empty()){
            int row = st.top().first;
            int col = st.top().second;
            st.pop();
            vis[row][col] = 1;
            if(row - 1 >= 0 && grid[row-1][col] == 1 && !vis[row-1][col]){
                vis[row-1][col] = 1;
                st.push({row-1, col});
            }
            if(col - 1 >= 0 && grid[row][col-1] == 1 && !vis[row][col-1]){
                vis[row][col-1] = 1;
                st.push({row, col-1});
            }
            if(row + 1 < m && grid[row+1][col] == 1 && !vis[row+1][col]){
                vis[row+1][col] = 1;
                st.push({row+1, col});
            }
            if(col + 1 < n && grid[row][col+1] == 1 && !vis[row][col+1]){
                vis[row][col+1] = 1;
                st.push({row, col+1});
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>>vis(m, vector<bool>(n, 0));
        for(int i = 0;i<m;i++){
            if(grid[i][0] == 1 && !vis[i][0]) dfs(grid, vis, i, 0);
            if(grid[i][n-1] == 1 && !vis[i][n-1]) dfs(grid, vis, i, n-1);
        }
        for(int j = 0;j<n;j++){
            if(grid[0][j] == 1 && !vis[0][j]) dfs(grid, vis, 0, j);
            if(grid[m-1][j] == 1 && !vis[m-1][j]) dfs(grid, vis, m-1, j);
        }
        for(int i = 1;i<m-1;i++){
            for(int j = 1;j<n-1;j++){
                if(grid[i][j] == 1 && !vis[i][j]) count++;
            }
        }
        return count;
    }
};