class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;

        queue<pair<pair<int, int>, int>>q;
        vector<int>x = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int>y = {-1, 0, 1, 1, 1, 0, -1, -1};
        q.push({{0, 0}, 1});
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int wt = q.front().second;
            q.pop();
            if(r == n-1 && c == n-1) return wt;
            for(int i = 0;i<8;i++){
                if(r + x[i] >= 0 && c + y[i] >= 0 && r+x[i] < n && c+y[i]<n){
                    if(!grid[r+x[i]][c+y[i]]){
                        q.push({{r+x[i], c+y[i]}, wt+1});
                        grid[r+x[i]][c+y[i]] = 1;
                    }
                }
            }
        }
        return -1;
    }
};