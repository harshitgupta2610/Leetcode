class Solution {
public:
    void twosum(vector<int>& nums, int k, vector<vector<int>>& result, int target){
        int i = k, j = nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]>target){
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{
                result.push_back({-target, nums[i], nums[j]});
                while(i < j && nums[i] == nums[i+1]) i++;
                while(i < j && nums[j] == nums[j-1]) j--;
                i++; 
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        
    vector<vector<int>> result;
        int n= nums.size();
        if(n<3){
            return {};
        }

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int n1 = nums[i];
            int target = n1;
            twosum(nums, i+1, result, -nums[i]);
        }
        return result;
    }
};