class Solution {
public:
    int t[2505][2505];
    int solve(vector<int> &nums,int idx ,int prev){
        if(idx>=nums.size()){
            return 0;
        }
        if(t[idx][prev+1]!=-1){
            return t[idx][prev+1];
        }
        int take =0;
        if(prev == -1 ||  nums[prev] < nums[idx]){
            take =1 + solve(nums,idx+1,idx);
        }
        int skip = solve(nums,idx+1,prev);
        return t[idx][prev+1] =  max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n =nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums,0,-1);
    }
};