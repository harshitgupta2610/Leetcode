class Solution {
public:
    int solve(vector<int> &nums, int n , vector<vector<int>> &dp , int idx ,  int prev){
        if(idx>=n){
            return 0;
        }
        if(dp[idx][prev+1]!=-1){
            return dp[idx][prev+1];
        }
        int take =0;
        if(prev==-1|| nums[prev]<nums[idx]){
            take= 1 + solve(nums,n,dp,idx+1,idx);
        }
        int skip = solve(nums,n,dp,idx+1,prev);
        return dp[idx][prev+1] =  max(skip,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(nums,n,dp,0,-1);
    }
};