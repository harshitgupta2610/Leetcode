#include <vector>
#include <algorithm>

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_len = 1;
        for (int i = 0; i < n; ++i) {
            int mask = nums[i];
            int current_len = 1; 
            for (int j = i + 1; j < n; ++j) {
                if ((mask & nums[j]) != 0) {
                    break;
                }
                mask |= nums[j];
                current_len++; 
            }
            max_len = max(max_len, current_len);
        }

        return max_len;
    }
};