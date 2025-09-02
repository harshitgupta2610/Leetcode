class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        // count frequencies
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        int maxi = INT_MIN;
        int ans = -1;

        for(auto &it : mp){
            if(maxi < it.second){
                maxi = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};
