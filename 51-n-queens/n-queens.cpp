class Solution {
public:
    bool is_safe(int row, int col, int n, vector<string>&board){
        int prow = row;
        int pcol = col;
        while(row >= 0 && col>=0){
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = prow;
        col = pcol;
        while(col>=0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        row = prow;
        col = pcol;
        while(row<n && col>=0){
            if(board[row][col] == 'Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void genfun(int col, int n, vector<string>&board, vector<vector<string>>&ans){
        if(col == n){
            ans.push_back(board);
            return;
        }
        for(int i = 0;i<n;i++){
            if(is_safe(i, col, n, board)){
                board[i][col] = 'Q';
                genfun(col+1, n, board, ans);
                board[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n, '.');
        for(int i = 0;i<n;i++) board[i] = s;
        genfun(0, n, board, ans);
        return ans;
    }
};