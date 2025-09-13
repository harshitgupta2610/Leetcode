class Solution {
public:
    int t[101];
    int solve(vector<int>&nums,int idx,int n){
        if(idx>n){
            return 0;
        }
        if(t[idx]!=-1){
            return t[idx];
        }
        int take  = nums[idx] + solve(nums,idx+2,n);
        int skip = solve(nums,idx+1,n);
        return t[idx] =  max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n  = nums.size();
        if(n==1){
            return nums[0];
        }
        // if(n==2){
        //     return max(nums[0],nums[1]);
        // }
        memset(t,-1,sizeof(t));
        int take0th = solve(nums,0,n-2);
        memset(t,-1,sizeof(t));
        int take1st = solve(nums,1,n-1);
        return max(take0th,take1st);
    }
};