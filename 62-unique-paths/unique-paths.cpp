class Solution {
public:
    int helper(int i , int j,int m, int n,vector<vector<int>> &dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i<0 || i>=m || j<0 || j>=n){
            return 0;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        int l = helper(i+1,j,m,n,dp);
        int r = helper(i,j+1,m,n,dp);
        return dp[i][j]= l+r;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m+1,vector<int> (n+1,0));
        return helper(0,0,m,n,dp);
    }
};