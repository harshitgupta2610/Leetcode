class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        set<int> st;
        for(int i =0;i<n;i++){
            if(st.find(nums[i])!=st.end()){
                ans = nums[i];
            }else{
            st.insert(nums[i]);}
        }
        return ans;
    }
};