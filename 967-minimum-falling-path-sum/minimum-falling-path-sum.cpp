class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), mini;

        for(int i = n-1;i>0;i--){
            for(int j = 0;j<m;j++) {
                mini = matrix[i][j];
                if(j - 1 >= 0 && mini > matrix[i][j-1]) mini = matrix[i][j-1];
                if(j + 1 < m && mini > matrix[i][j+1]) mini = matrix[i][j+1];
                matrix[i-1][j] += mini;
            }
        }
        
        mini = matrix[0][0];
        for(int i = 1;i<m;i++) mini = min(mini, matrix[0][i]);

        return mini; 

    }
};