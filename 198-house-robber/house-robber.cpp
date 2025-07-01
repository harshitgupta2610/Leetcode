class Solution {
public:
    int t[101];
    int solve(vector<int>& nums,int idx,int n){
        if(idx>=n){
            return 0;
        }
        if(t[idx]!=-1){
            return t[idx];
        }
        int take = nums[idx] + solve(nums,idx+2,n);
        int skip = solve(nums,idx+1,n);
        return t[idx] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n =nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums, 0, n);
    }
};