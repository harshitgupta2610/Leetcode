class Solution {
public:
    static bool func ( string &word1 ,string &word2){
        return word1.length()<word2.length();
    }
    bool  valid(string &prev,string &idx){
        int mm = prev.length();
        int nn = idx.length();
        if(mm>=nn||nn-mm != 1){
            return false;
        }
        int  i=0;int j=0;
        while(i<mm && j<nn){
            if(prev[i]==idx[j]){
                i++;
            }
            j++;
        }
        return i==mm;
    }
    int helper(vector<string>& words,int n, int idx, int prev,vector<vector<int>> &dp ){
        if(idx>=n){
            return 0;
        }
        int take=0;
        if(dp[idx][prev+1]!=-1){
            return dp[idx][prev+1];
        }
        if(prev ==-1|| valid(words[prev],words[idx])){
            take = 1+ helper(words,n,idx+1,idx,dp);
        }
        int skip = helper(words,n,idx+1,prev,dp);
        return dp[idx][prev+1] =max(take,skip);
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));
        sort(begin(words),end(words),func);
        return  helper(words,n,0,-1,dp);
    }
};