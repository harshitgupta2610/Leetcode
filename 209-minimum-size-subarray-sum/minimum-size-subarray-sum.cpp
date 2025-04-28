class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n =nums.size();
        int i =0;
        int j =0;
        int result =INT_MAX;
        int curr =0 ;
        while(j<n){
            curr+=nums[j];
            while(curr>=target){
                result = min(result,(j-i+1));
                curr-=nums[i];
                i++;
            }
            j++;
        }
        if( result == INT_MAX){
            return 0;
        }
        return result;
    }
};