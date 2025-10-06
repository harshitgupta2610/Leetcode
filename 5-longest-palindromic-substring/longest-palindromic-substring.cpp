class Solution {
public:
    bool helper(string &str, int i , int j){
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n =s.size();
        int start =0;
        int maxlen =1;
        int len =0;
        for(int i=0;i<n;i++){
            for(int j =i;j<n;j++){
                if(helper(s,i,j)){
                    if(maxlen<(j-i+1)){
                        start =i;
                        maxlen = j-i+1;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};