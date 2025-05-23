class Solution {
public:
    int helper(vector<int>& nums,int idx,vector <int> &dp ){
        int n = nums.size();
        if(idx>n-1){
        return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        return dp[idx]=max((helper(nums,idx+2,dp)+nums[idx]),helper(nums,idx+1,dp));
    }
    int rob(vector<int>& nums) {
        int  n = nums.size();
        vector <int> dp (n,-1);
        int res =helper(nums,0,dp);
        return res;
    }
};