class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxe = *max_element(nums.begin(),nums.end());
        int n =nums.size();
        long long result=0;

        vector<int> res;

        for(int i =0 ;i <n;i++){
            if(nums[i]==maxe){
                res.push_back(i);
            }
            int size=res.size();
            if(size>=k){
                int last = res[size-k];
                result+=(last+1);
            }
        }
        return result;
    }
};