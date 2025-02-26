class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int curr = nums[0];
        int max1 =nums[0];
        int min1=nums[0];
        for(int i =1;i<nums.size();i++){
            curr = max(nums[i],curr+nums[i]);
            max1 =max(max1,curr);
        }
        curr = nums[0];
        for(int i =1;i<nums.size();i++){
            curr = min(nums[i],curr+nums[i]);
            min1 =min(min1,curr);
        }
        return max(max1,abs(min1));
    }
};