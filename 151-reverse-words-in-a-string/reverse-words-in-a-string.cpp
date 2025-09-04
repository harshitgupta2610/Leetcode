class Solution {
public:
    string reverseWords(string s) {
        int n  =s.length();
        stringstream ss(s);
        string token = "";
        string result ="";
        while(ss>>token){
            result = token + " " +result;
        }
        int m = result.length();
        return result.substr(0,m-1);
    }
};