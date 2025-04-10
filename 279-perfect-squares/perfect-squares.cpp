class Solution {
public:
    int  helper(int n,vector<int> &dp){
        int ans = INT_MAX;
        if(n==0){
            return 0 ;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        for( int i =1;i*i<=n;i++){
            int result = 1+ helper(n- (i*i),dp);
            ans = min(ans,result);
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};