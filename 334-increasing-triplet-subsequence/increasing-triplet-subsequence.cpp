class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n =nums.size();
        int first =nums[0];
        int second =INT_MAX;
        for(int i =0;i<n;i++){
            if(nums[i]<=first){
                first=nums[i];
            }
            else if(nums[i]<=second){
                second=nums[i];
            }
            else if(second<nums[i]){
                return true;
            }
        }
        return false;
    }
};