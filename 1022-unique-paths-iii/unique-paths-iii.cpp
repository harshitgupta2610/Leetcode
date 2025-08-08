class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, int count) {
        if (i<0||j<0||j>=grid[0].size()||i>=grid.size()||grid[i][j] == -1){
            return 0;
        }
        if (grid[i][j] == 2){
            return (count == 1) ? 1 : 0; 
        }
        grid[i][j] = -1;
        int paths = helper(grid, i + 1, j, count - 1) +
                    helper(grid, i - 1, j, count - 1) +
                    helper(grid, i, j + 1, count - 1) +
                    helper(grid, i, j - 1, count - 1);
        grid[i][j] = 0;
        return paths;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x,y,count = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                   x = i;
                   y = j;
                }
                if (grid[i][j] != -1)count++; 
            }
        }
        
        return helper(grid,x,y,count);
    }
};