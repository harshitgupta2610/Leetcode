class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int count=0;
        // while(j<n){
        //     if(j-i+1==3){
        //         int mid = (j+i)/2;
        //         if(2*(nums[i]+nums[j])==(nums[i+1])){
        //             count++;
        //         }
        //         i++;
        //     }
        //     j++;
        // }
        for(int i =1;i<n-1;i++){
            if(2*(nums[i-1]+nums[i+1])==(nums[i])){
                count++;
            }
        }
        return count;
    }
};