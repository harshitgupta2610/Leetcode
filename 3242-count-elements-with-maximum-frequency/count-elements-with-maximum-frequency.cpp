class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
        }
        int maxsize =0;
        for(auto &it: mp){
            if(it.second>maxsize){
                maxsize = it.second;
            }
        }
        cout<<maxsize;
        int res =0;
        for( auto &it: mp){
            if(maxsize==it.second){
                res+=it.second;
            }
        }
        return res;
    }
};