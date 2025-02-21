
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int t=0;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        vector<int> dx = {-1, 0, 1, 0}; 
        vector<int> dy = {0, 1, 0, -1}; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                     visited[i][j]=true;
                }
            }
        }
        while (!q.empty()) {
            auto p = q.front();
            int i = p.first.first;
            int j = p.first.second;
            t = p.second; 
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 && !visited[nx][ny]) {
                    grid[nx][ny] = 2;
                    visited[nx][ny]=true;
                    q.push({{nx, ny}, t + 1});
                    
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return t;
    }
};