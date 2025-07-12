class Solution {
public:
    int m,n;
    vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    vector<vector<int>> dp;
    long long MOD = 1e9+7;
    bool isSafe(int i_new ,int  j_new){
        return (i_new>=0 && i_new<m && j_new >=0 && j_new < n) ;
    }
    
    int dfs(int i,int j,vector<vector<int>>& grid){
        int ans=1;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(auto dir : dirs){
            int i_new = i + dir[0];
            int j_new = j + dir[1];
            if(isSafe(i_new,j_new) && grid[i_new][j_new]>grid[i][j]){
                ans=max(ans,1+ dfs(i_new,j_new,grid));
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& grid) {
        m= grid.size();
        n= grid[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, -1));  
        int result =0;
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                result = max(result , dfs(i,j,grid));
            }
        }
        return result;
    }
};