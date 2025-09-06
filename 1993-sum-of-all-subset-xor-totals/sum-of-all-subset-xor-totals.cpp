class Solution {
public:
    void solve(vector<int>& nums ,int idx ,vector<int>& currSubset ,vector<vector<int>> &subsets){
        if(idx==nums.size()){
            subsets.push_back(currSubset);
            return;
        }
        currSubset.push_back(nums[idx]);
        solve(nums,idx+1,currSubset,subsets);
        currSubset.pop_back();
        solve(nums,idx+1,currSubset,subsets);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> currSubset;
        solve(nums,0,currSubset,subsets);
        int result =0;
        for(auto &curr : subsets){
            int xoor = 0;
            for(int num:curr){
                xoor^=num;
            }
            result+=xoor;
        }
        return result;
    }
};