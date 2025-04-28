class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i =0 ;
        int j =0;
        long long result=0;
        int count=0;
        int maxe = *max_element(nums.begin(),nums.end());
        cout<<maxe;
        while(j<n){
            if(nums[j]==maxe){
                count++;
            }
            while(count>=k){
                result += (n-j);
                if(nums[i]==maxe){
                    count--;
                }
                i++;
            }
            j++;
        }
        return result;
    }
};