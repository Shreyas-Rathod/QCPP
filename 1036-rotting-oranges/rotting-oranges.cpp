class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cc = 0, tc = 0, minutes = 0;
        queue<pair<int,int>> q;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    cc++;
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty()){
            int currCount = cc;
            cc = 0;        
            while(currCount--) {
                auto [r, c] = q.front();
                q.pop();   
                
                if(r-1 >= 0 && grid[r-1][c] == 1) {
                    grid[r-1][c] = 2;
                    q.push({r-1, c});
                    cc++;
                }
                if(c+1 < n && grid[r][c+1] == 1) {
                    grid[r][c+1] = 2;
                    q.push({r, c+1});
                    cc++;
                }
                if(r+1 < m && grid[r+1][c] == 1) {
                    grid[r+1][c] = 2;
                    q.push({r+1, c});
                    cc++;
                }
                if(c-1 >= 0 && grid[r][c-1] == 1) {
                    grid[r][c-1] = 2;
                    q.push({r, c-1});
                    cc++;
                }
            }
            if(cc > 0) minutes++;
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) 
                    return -1;
            }
        }
        return minutes;
    }
};
