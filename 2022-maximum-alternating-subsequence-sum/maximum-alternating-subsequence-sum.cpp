class Solution {
public:
    long long helper(vector<int> &nums, int n , int idx, bool flag,vector<vector<long long>> &dp){
        if(idx >= n) {
            return 0;
        }
        if(dp[idx][flag]!=-1){
            return dp[idx][flag];
        }
        long long skip= helper(nums, n, idx + 1 ,flag,dp);
        long long val = nums[idx];
        if(flag == false){
            val = -val;
        }
        long long take = helper(nums, n, idx+1,!flag,dp)+val;

        return dp[idx][flag]= max(take, skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        // int n = nums.size();
        // int m = 2;
        // vector<vector<long long>> dp(n, vector<long long>(2, -1));
        // return helper(nums,n, 0, true,dp);


        //OPTIMISED APP
        int n = nums.size();

        long long even = nums[0];
        long long odd = 0;
        for (int i = 1; i < n; i++) {
            even = max(even, odd + nums[i]);
            odd = max(odd, even - nums[i]);
        }
        return even;
        
    }
};