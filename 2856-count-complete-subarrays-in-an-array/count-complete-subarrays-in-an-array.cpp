class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        int n = nums.size();
        for(int i =0;i<n;i++){
            st.insert(nums[i]);
        }
        int c = st.size();
        unordered_map<int,int> mp;
        int i =0;
        int j =0;
        int res=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()==c){
                res+=(n-j);
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return res;
    }
};