class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        // Dynamically allocate the dp array based on the size of the string
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0, n - 1, s, dp);
    }

    int helper(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i >= j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (s[i] == s[j]) {
            return dp[i][j] = helper(i + 1, j - 1, s, dp);
        } else {
            return dp[i][j] = 1 + min(helper(i + 1, j, s, dp), helper(i, j - 1, s, dp));
        }
    }
};