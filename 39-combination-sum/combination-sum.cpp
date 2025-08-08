class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int>& candidates, int target,vector<int> &curr,int idx){
        if(target<0){
            return;
        }
        if(target==0){
            result.push_back(curr);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            curr.push_back(candidates[i]);
            solve(candidates,target-candidates[i],curr,i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(candidates,target,curr,0);
        return result;
    }
};