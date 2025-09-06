class Solution {
public:
    int longestPalindrome(string s) {
        int n =s.length();
        unordered_map<int,int> mp;

        int result =0;
        for(char &ch : s){
            mp[ch]++;
        }
        bool check =  false;
        for(auto &it : mp){
            if(it.second%2==0){
                result+=it.second;
            }
            else{
                result += it.second - 1;
                check = true;
            }
        }
        if(check){
            result+=1;
        }
        return result;
    }
};