// class Solution {
// public:
//     int helper(vector<int>& nums, int n , int idx , int prev, vector<vector<int>> &dp){
//         if(idx>=n){
//             return  0;
//         }
//         if(dp[idx][prev+1]!=-1){
//             return dp[idx][prev+1];
//         }
//         int take = 0;
//         if(prev==-1 || nums[idx]> nums[prev]){
//              take = 1+helper(nums,n , idx+1,idx,dp);
//         }
//         int skip= helper(nums,n,idx+1,prev,dp);
//         return dp[idx][prev+1]=max(take,skip);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n+2,vector<int> (n+2,-1));
//         return helper(nums, n, 0, -1,dp);
//     }
// };




class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n,1);
        int max1 =1;
        for(int i =0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]= max(dp[i],dp[j]+1);
                    max1 =max(dp[i],max1);
                }
            }
        }
        return max1;
    }
};