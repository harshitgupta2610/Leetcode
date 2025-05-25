class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int ans =0;
        int n =s.size();
        for(int i = 0 ;i<n;i++){
            for(int j =0 ;j<n;j++){
                if(s[i]==t[j]){
                    ans+=abs(i-j);
                }
            }
        }
        return ans;
    }
};