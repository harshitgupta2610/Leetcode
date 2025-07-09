class Solution {
public:
    int LCS(string& s1, string& s2, int m, int n, vector<vector<int>>& dp) {
        if (m == 0 || n == 0) {
            return 0;
        }

        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        if (s1[m - 1] == s2[n - 1]) {
            dp[m][n] = 1 + LCS(s1, s2, m - 1, n - 1, dp);
        } else {
            dp[m][n] = max(LCS(s1, s2, m, n - 1, dp), LCS(s1, s2, m - 1, n, dp));
        }

        return dp[m][n];
    }

    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        int m = s.length();

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
        return LCS(s, s1, m, m, dp);
    }
};
