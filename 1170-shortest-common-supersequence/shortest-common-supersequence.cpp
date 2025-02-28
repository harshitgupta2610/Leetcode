class Solution {
public:
    int LCS(string& s1, string& s2, int m, int n,vector<vector<int>> &t) {
        if (m == 0) return t[m][n] = n;
        if (n == 0) return t[m][n] = m;
        if(t[m][n] != -1){
            return t[m][n];
        }
        if(s1[m-1]==s2[n-1]){
            return t[m][n]= 1 + LCS(s1,s2,m-1,n-1,t);
        }
        else {
            return t[m][n] = 1 + min(LCS(s1, s2, m-1, n, t), LCS(s1, s2, m, n-1, t));
        }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        LCS(str1, str2, m, n, dp);
        int i = m, j = n;
        string result = "";
        while (i>0 && j>0) {
            if (str1[i-1] == str2[j-1]) {
                result.push_back(str1[i-1]);
                i--;
                j--; 
            }
            else if(dp[i-1][j]<dp[i][j-1]) { 
                result.push_back(str1[i-1]);
                i--;
            } 
            else {
                result.push_back(str2[j-1]);
                j--;
            }
        }
        while (i > 0){ 
            result.push_back(str1[--i]);
        }
        while (j > 0){ 
            result.push_back(str2[--j]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

