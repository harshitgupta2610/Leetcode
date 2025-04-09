class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> st;
        int count =0;
        for(int i =0;i<nums.size();i++){
            int x =nums[i];
            if(nums[i]>k && st.find(x)==st.end()){
                count++;
                st.insert(nums[i]);
            }
        }
          int mini = *min_element(nums.begin(), nums.end());
            if (mini < k) return -1;
        return count;
    }
};