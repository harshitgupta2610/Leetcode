class Solution {
public:
    int LCS(string& s1, string& s2, int m, int n,vector<vector<int>> &t) {
        if(m==0||n==0){
            return t[m][n] = 0;
        }
        if(t[m][n] != -1){
            return t[m][n];
        }
        if(s1[m-1]==s2[n-1]){
            return t[m][n]= 1 + LCS(s1,s2,m-1,n-1,t);
        }
        else{
            t[m][n]= max (LCS(s1,s2,m,n-1,t),LCS(s1,s2,m-1,n,t));
        }
        return t[m][n];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> t(m+1,vector<int>(n+1,-1));  
        return LCS(text1, text2, m, n,t);
    }
};