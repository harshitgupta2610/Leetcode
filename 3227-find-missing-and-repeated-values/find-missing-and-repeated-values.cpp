class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                mp[grid[i][j]]++;
            }
        }

        int x = -1;
        int y = -1;
        for(int i = 1; i <= n * m; i++) {
            if(mp[i] == 2) {
                x = i;
            } else if(mp[i] == 0) {
                y = i;
            }
        }

        ans.push_back(x);
        ans.push_back(y);

        return ans;
    }
};