class Solution {
public:
    bool genfun(vector<vector<char>>& board, string word, int k, int i, int j){
        if(word[k]==board[i][j]){
            if(k+1==word.size()) return true;
            char temp = board[i][j];
            board[i][j] = '0';
            if(i-1 >= 0 && genfun(board, word, k+1, i-1, j)) return true;
            if(i+1 < board.size() && genfun(board, word, k+1, i+1, j)) return true;
            if(j-1 >= 0 && genfun(board, word, k+1, i, j-1)) return true;
            if(j+1 < board[0].size() && genfun(board, word, k+1, i, j+1)) return true; 
            board[i][j] = temp;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(word[0] == board[i][j] && genfun(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};