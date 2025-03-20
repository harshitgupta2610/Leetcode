class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // unordered_map<int,int> mp;
        // int n = nums.size();
        // for(int i=0; i<n; i++){
        //     if(mp.count(nums[i])){
        //         if(abs(i-mp[nums[i]])<=k){
        //             return true;
        //         }
        //     }
        //     mp[nums[i]] = i;
        // }
        // return false;

        int n = nums.size();
        unordered_set<int>st ;
        int i =0;int j=0;
        while(j<n){
            if(abs(i-j)>k){
                st.erase(nums[i]);
                i++;
            }
            if(st.find(nums[j])!=st.end()){
                return true;
            }
            st.insert(nums[j]);
            j++;
        }
        return false;
    }
};