class Solution {
public:
    void dfs(vector<vector<char>>&grid,int i, int j,int n,int m){
        if(grid[i][j]=='0'||i>=n||i<0||j>=m||j<0){
            return;
        }
        grid[i][j]='0';
        if(i+1<n){
            dfs(grid,i+1,j,n,m);
        }
        if(i-1>=0){
            dfs(grid,i-1,j,n,m);
        }
        if(j+1<m){
            dfs(grid,i,j+1,n,m);
        }
        if(j-1>=0){
            dfs(grid,i,j-1,n,m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count =0;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};