class Solution {
public:
    bool isvalid(vector<vector<char>>&board, int i, int j, char k){
        for(int l = 0;l<9;l++){
            if(board[i][l] == k || board[l][j] == k) return false;
            if(board[3*(i/3)+l/3][3*(j/3)+l%3] == k) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>&board){
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board.size();j++){
                if(board[i][j] == '.'){
                    for(char k = '1';k<='9';k++){
                        if(isvalid(board, i, j, k)){
                            board[i][j] = k;
                            if(solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }
};