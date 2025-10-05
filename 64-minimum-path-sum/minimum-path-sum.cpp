class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int>prev(m, 0), curr(m, 0);
        prev[0] = grid[0][0];

        for(int i = 1;i<m;i++) prev[i] = prev[i-1] + grid[0][i];
        for(int i = 1;i<n;i++){
            curr[0] = prev[0] + grid[i][0];
            for(int j = 1;j<m;j++){
                curr[j] = grid[i][j] + min(curr[j-1], prev[j]);
            }
            prev = curr;
        }

        return prev[m-1];
    }
};