class Solution {
public:
    int n, m;
    
    bool helper(int i, int j, vector<vector<char>>& board, string& word, int idx) {
        if(idx == word.length()){
            return true;
        }
        if(i<0 || i>=m || j<0 || j>=n || board[i][j] == '$'){
            return false;
        }
        if(board[i][j]!=word[idx]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        bool found = helper(i + 1, j, board, word, idx + 1) ||
                     helper(i - 1, j, board, word, idx + 1) ||
                     helper(i, j + 1, board, word, idx + 1) ||
                     helper(i, j - 1, board, word, idx + 1);

        board[i][j] = temp;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(board[i][j]== word[0] && helper(i,j,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
