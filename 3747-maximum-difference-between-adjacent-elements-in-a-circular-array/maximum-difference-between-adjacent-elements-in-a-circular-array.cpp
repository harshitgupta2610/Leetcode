class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int max1 =0;
        for(int i =1;i<n;i++){
            int x = abs(nums[i]-nums[i-1]);
            max1 = max(max1 ,x );
        }
        int x2 = abs(nums[n-1]-nums[0]);
        max1 = max(max1 ,x2 );
        return max1;
    }
};