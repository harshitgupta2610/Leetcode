class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int count;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            count = 0;
            int sum = 0;

            for (int j = 1; j <= nums[i]; j++) {
                if (nums[i] % j == 0) {   
                    count++;
                    sum += j;      
                }
                if (count > 4) break; // Early termination
            }

            if (count == 4) {            // FIX 3
                ans += sum;
            }
        }
        return ans;
    }
};
