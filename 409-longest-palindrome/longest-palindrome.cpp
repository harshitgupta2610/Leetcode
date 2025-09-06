class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        int result =0;
        unordered_set<char> st;
        for(char & ch : s){
            if(st.count(ch)){
                st.erase(ch);
                result+=2;
            }
            else{
                st.insert(ch);
            }
        }
        if(!st.empty()){
            result+=1;
        }
        return result;
    }
};