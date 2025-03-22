class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n, -1);
        for (int i = 0; i < n; ++i) {
            if (i-k >= 0 && i+k < n) {
                long long sum = nums[i];
                for (int j = i-1; j>=i-k; --j) {
                    sum += nums[j];
                }
                for (int j = i+1; j <= i+k; ++j) {
                    sum += nums[j];
                }
                result[i] = sum/(2*k+1);
            }
        }
        return result;
    }
};