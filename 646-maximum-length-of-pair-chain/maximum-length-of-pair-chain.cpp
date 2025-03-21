class Solution {
public:
    int n ;
    int helper(vector<vector<int>>& pairs,int idx, int prev, vector<vector<int>> &dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][prev+1]!=-1){
            return dp[idx][prev+1];
        }
        int take =0;
        if(prev==-1||pairs[idx][0]>pairs[prev][1]){
             take = 1+helper(pairs,idx+1,idx,dp);
        }
        int skip = helper(pairs,idx+1,prev,dp);
        return dp[idx][prev+1]=max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n = pairs.size();
        vector<vector<int>> dp (n+1,vector<int>(n+1,-1));
        sort(begin(pairs),end(pairs));
        return helper(pairs,0,-1,dp);
    }
};