class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n =s.size();
        int i =0 ;
        int j =0 ;
        int curr=0;
        int result =0 ;
        while(j<n){
            curr += abs(s[j]-t[j]);
            while(curr>maxCost){
                curr -= abs(s[i]-t[i]);
                i++;
            }
            result = max(result,j-i+1);
            j++;
        }
        return result;
    }
};