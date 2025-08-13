class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), area = 0;
        area += accumulate(matrix[0].begin(), matrix[0].end(), 0);
        for(int i = 1;i<n;i++) area += matrix[i][0];
        for(int i = 1;i<n;i++){
            for(int j = 1;j<m;j++){
                if(matrix[i][j]) matrix[i][j] += min(matrix[i-1][j-1], min(matrix[i][j-1], matrix[i-1][j]));
                area += matrix[i][j];
            }
        }
        
        return area;
    }
};