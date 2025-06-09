class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>>res(m, vector<int>(n, 0));
        vector<vector<bool>>vis(m, vector<bool>(n, 0));
        queue<pair<pair<int, int>, int>>q;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 0){
                    vis[i][j] = true;
                    q.push({{i, j}, 0});
                }
                else vis[i][j] = false;
            }
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            res[row][col] = dis;
            for(int i = 0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = true;
                    q.push({{nrow, ncol}, dis+1});
                }
            }
        }
        return res;
    }
};