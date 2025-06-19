class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>>q;
        vector<vector<int>>dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = 0;
        vector<int>x = {-1, 0, 1, 0};
        vector<int>y = {0, 1, 0, -1};
        q.push({{0, 0}, 0});

        while(!q.empty()){
            int row = q.top().first.first;
            int col = q.top().first.second;
            int diff = q.top().second;
            q.pop();
            if(row == m-1 && col == n-1) return diff;

            for(int i = 0;i<4;i++){
                int nr = row + x[i];
                int nc = col + y[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n){
                    int wt = max(abs(heights[nr][nc] - heights[row][col]), diff);
                    if(wt < dp[nr][nc]){
                        dp[nr][nc] = wt;
                        q.push({{nr, nc}, wt});
                    }
                }
            }
            
        }

        return 0;
    }
};