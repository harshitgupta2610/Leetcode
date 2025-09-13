class Solution {
public:
    int solve(vector<vector<int>>& pairs,int n,int idx,int prev,vector<vector<int>>& dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][prev+1]!=-1){
            return dp[idx][prev+1];
        }
        int take =0;
        if(prev==-1||pairs[prev][1]<pairs[idx][0]){
            take = 1+ solve(pairs,n,idx+1,idx,dp);
        }
        int skip = solve(pairs,n,idx+1,prev,dp);
        return dp[idx][prev+1] =  max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        sort(pairs.begin(),pairs.end());
        return solve(pairs,n,0,-1,dp);
    }
};