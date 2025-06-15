class Solution {
public:
    int sliding(vector<int>& nums, int k) {
        int n =nums.size();
        int i =0 ;
        int j =0 ;
        int result =0 ;
        unordered_map<int,int> mp;

        while(j<n){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            result += (j-i+1);
            j++;
        }
        return result;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return sliding(nums, k) - sliding(nums, k-1);
    }
};