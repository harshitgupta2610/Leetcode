class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int count=0;
        while(j<n){
            if(j-i+1==3){
                int mid = (j+i)/2;
                if((nums[i]+nums[j])==(nums[mid]/2.0)){
                    count++;
                }
                i++;
            }
            j++;
        }
        return count;
    }
};