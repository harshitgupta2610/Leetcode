class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            // int x= nums[i];
            // int y= nums[i+1];
            if(nums[i]==nums[i+1] && nums[i]!=0){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
            
        }
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }
        }
        while(j<n){
            nums[j] = 0;
            j++;
        }
        return nums;
    }
};