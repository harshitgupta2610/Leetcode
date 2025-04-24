class Solution {
public:
    
    void solve (vector<int>& nums,int i,vector<int> &temp,vector<vector<int>> &result){
        if(i>=nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(nums,i+1,temp,result);
        temp.pop_back();
        solve(nums,i+1,temp,result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> result;
       vector<int> temp;
       solve(nums,0,temp,result);
       return result;
    }
};