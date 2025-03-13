class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> ans;
        int n = gain.size();
        ans.push_back(0);
        for(int  i=0;i<n;i++){
            int x = gain[i]+ans.back();
            ans.push_back(x);
        }
        return *max_element(ans.begin(), ans.end());
    }
};