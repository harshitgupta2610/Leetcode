class Solution {
public:
    int LCS(string& s1, int m, int n, vector<vector<int>>& dp) {
        if (m>n) {
            return 0;
        }
        if(m==n){
            return 1;
        }
        if (dp[m][n] != -1) {
            return dp[m][n];
        }

        if (s1[m] == s1[n]) {
            dp[m][n] = 2 + LCS(s1, m+1, n-1, dp);
        } else {
            dp[m][n] = max(LCS(s1, m, n-1, dp), LCS(s1, m+1, n, dp));
        }

        return dp[m][n];
    }

    int longestPalindromeSubseq(string s) {
        int m = s.length();

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
        return LCS(s, 0, m, dp);
    }
};
