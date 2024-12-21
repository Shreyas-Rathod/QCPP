class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int col0 = 1;
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(matrix[i][j] == 0){
                    if(j == 0) col0 = 0;
                    else matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1;i<row;i++){
            if(matrix[i][0] == 0){
                int j = 1;
                while(j<col) matrix[i][j++] = 0;
            }
        }
        for(int j = 1;j<col;j++){
            if(matrix[0][j] == 0){
                int i = 1;
                while(i<row) matrix[i++][j] = 0;
            }
        }
        int i = 0, j = 0;
        if(matrix[0][0] == 0) while(j<col) matrix[0][j++] = 0;
        if(col0 == 0) while(i<row) matrix[i++][0] = 0;
    }
};