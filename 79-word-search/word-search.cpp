class Solution {
public:
    int n, m;
    
    bool helper(int i, int j, vector<vector<char>>& board, string& word, int idx, vector<vector<int>>& visited) {
        if (idx == word.size()) return true; 
        
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[idx] || visited[i][j])
            return false;
        
        visited[i][j] = 1; 
        bool found = helper(i + 1, j, board, word, idx + 1, visited) ||
                     helper(i - 1, j, board, word, idx + 1, visited) ||
                     helper(i, j + 1, board, word, idx + 1, visited) ||
                     helper(i, j - 1, board, word, idx + 1, visited);
        
        visited[i][j] = 0;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) { 
                    if (helper(i, j, board, word, 0, visited)) return true;
                }
            }
        }
        return false;
    }
};
