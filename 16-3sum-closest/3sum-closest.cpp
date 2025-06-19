class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minn=0;
        int n =nums.size();
        sort(nums.begin(),nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        for(int k =0; k <n-2;k++){
            int i = k+1;
            int j = n-1;
            while(i<j){
                int sum = nums[k]+nums[i]+nums[j];
                if(abs(target-sum) < abs(target-closestSum)) {
                    closestSum = sum;
                }
                if(sum<target){
                    i++;
                }
                else{
                    j--;
                }
            }
        }
        return closestSum;
    }
};