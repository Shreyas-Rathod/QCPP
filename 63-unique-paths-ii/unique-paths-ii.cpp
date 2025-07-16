class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(m == 0 || obstacleGrid[0][0]) return 0;

        vector<int>curr(n, 0);
        curr[0] = 1;
        
        for(int r = 0;r<m;r++){
            for(int c = 0;c<n;c++){
                if(obstacleGrid[r][c]) curr[c] = 0;
                else {if(c > 0) curr[c] += curr[c-1];}
            }
        }

        return curr[n-1];
    }
};