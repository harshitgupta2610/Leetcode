class Solution {
public:
    int minCost(string s, vector<int>& res) {
        int ans =0;
        int n =s.size();
        int prevMax = 0;
        for(int i =0;i<n;i++){
            if(i > 0 && s[i] != s[i-1]) {
                prevMax = 0;
            }
            int curr = res[i];
            ans += min(prevMax, curr);
            prevMax = max(prevMax, curr);
        }
        return ans;
    }
};