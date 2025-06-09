class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>>&vis, int i, int j){
        int m = board.size();
        int n = board[0].size();
        stack<pair<int, int>>st;
        st.push({i, j});
        while(!st.empty()){
            int row = st.top().first;
            int col = st.top().second;
            st.pop();
            if(row - 1 >= 0 && board[row-1][col] == 'O' && !vis[row-1][col]){
                vis[row-1][col] = true;
                st.push({row-1, col});
            }
            if(row + 1 < m && board[row+1][col] == 'O' && !vis[row+1][col]){
                vis[row+1][col] = true;
                st.push({row+1, col});
            }
            if(col - 1 >= 0 && board[row][col-1] == 'O' && !vis[row][col-1]){
                vis[row][col-1] = true;
                st.push({row, col-1});
            }
            if(col + 1 < n && board[row][col+1] == 'O' && !vis[row][col+1]){
                vis[row][col+1] = true;
                st.push({row, col+1});
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>>vis(m, vector<bool>(n, false));
        for(int i = 0;i<m;i++){
            if(board[i][0] == 'O' && !vis[i][0]) dfs(board, vis, i, 0);
            if(board[i][n-1] == 'O' && !vis[i][n-1]) dfs(board, vis, i, n-1);
        }
        for(int j = 0;j<n;j++){
            if(board[m-1][j] == 'O' && !vis[m-1][j]) dfs(board, vis, m-1, j);
            if(board[0][j] == 'O' && !vis[0][j]) dfs(board, vis, 0, j);
        }
        
        for(int i = 1;i<m-1;i++){
            for(int j = 1;j<n-1;j++){
                if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};