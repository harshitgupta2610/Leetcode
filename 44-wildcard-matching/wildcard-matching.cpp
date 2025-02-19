class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        // Base case: empty string matches empty pattern
        dp[0][0] = true;

        // Fill first row (when `s` is empty, but `p` contains `'*'`)
        for (int j = 1; j <= m; j++) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-1];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];  // '*' matches 0 or more characters
                }
                else if (p[j-1] == '?' || s[i-1] == p[j-1]) {
                    dp[i][j] = dp[i-1][j-1];  // Match single character
                }
            }
        }

        return dp[n][m];
    }
};




// class Solution {
// public:
//     bool func(string s, string p, int i,int j){
//     if(i==s.size()&& j==p.size())return true;
//     for(int k=0;k<p.size();k++){
//         if(p[k]=='*'){
//             return true;
//         }
//     }
//     if(j==p.size())return false;
//     bool ans = false;
//     bool x = false;
//     bool y = false;
//     if(p[j]=='*'){
//         ans = func(s,p,i,j+1)||func(s,p,i+1,j);
//     }
//     else if(p[j]=='?'){
//         x = func(s,p,i+1,j+1);
//     }
//     else{
//         if(s[i]==p[j]){
//             y = func(s,p,i+1,j+1);
//         }
//     }
//     return ans||x||y;
//     }
//     bool isMatch(string s, string p) {
//      return func(s,p,0,0);
//     }
// };

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int n = s.length();
//         int m = p.length();
//         for(int k=0;k<m;k++){
//             if(p[k]=='*'){
//                 return true;
//             }
//         }
//         int i = 0, j = 0,star = -1, match = 0;
//         while (i < n) {
//             if ( (s[i] == p[j] || p[j] == '?')) {
//                 i++;
//                 j++;
//             } 
//             else if ( p[j] == '*') {
//                 star = j;
//                 match = i;
//                 j++; 
//             } 
//             else if(star!=-1) {
//                 j=star + 1;
//                 match++;
//                 i=match;
//             } 
//             else {
//                 return false;
//             }
//         }
//         return j==m;
//     }
// };
