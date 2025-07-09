class Solution {
public:
int n;
    int solve(vector<int>& sati,int idx, int time,vector<vector<int>> &dp){

        if(idx==n){
            return 0;
        }
        if(dp[idx][time]!=-1){
            return dp[idx][time];
        }
        int take = sati[idx]*time + solve(sati,idx+1,time+1,dp);
        int skip = solve(sati,idx+1,time,dp);
        return dp[idx][time] = max(take,skip);
    }
    int maxSatisfaction(vector<int>& sati) {
         n = sati.size();
         vector<vector<int>> dp(n+1,vector<int>(n+1,-1) );
         sort(sati.begin(),sati.end());
        return solve(sati,0,1,dp);
    }
};