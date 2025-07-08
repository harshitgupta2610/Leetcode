class Solution {
public:
    int n;
    int solve(string &s,int idx, int prev,vector<vector<int>> &dp){
        if(idx>=n){
            return 0;
        }
        int flip = INT_MAX;
        int noflip = INT_MAX;
        if(dp[idx][prev]!=-1){
            return dp[idx][prev];
        }
        if(s[idx]=='0'){
            if(prev==1){
                flip = 1 + solve(s,idx+1,1,dp);
            }else{
                flip = 1 + solve(s,idx+1,1,dp);
                noflip = solve(s,idx+1,0,dp);
            }
        }
        else if(s[idx]=='1'){
            if(prev== 1 ){
                noflip =solve(s,idx+1,1,dp);
            }else{
                flip = 1 + solve(s,idx+1,0,dp);
                noflip = solve(s,idx+1,1,dp);
            }
        }
        return dp[idx][prev]=min(flip,noflip);
    }
    int minFlipsMonoIncr(string s) {
        n =s.length();
        vector<vector<int>> dp(n+1,vector<int> (2,-1));
        return solve(s,0,0,dp);
    }
};