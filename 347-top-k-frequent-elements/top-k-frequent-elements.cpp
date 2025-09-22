class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n =nums.size();
        map<int,int> mp;
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(vec[i].first);
        }
        return res;
    }
};