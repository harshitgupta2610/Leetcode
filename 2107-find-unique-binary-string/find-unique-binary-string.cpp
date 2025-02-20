class Solution {
public:
    void helper(int n, string curr, unordered_set<string>&str) {
        if (curr.size() == n) {
        str.insert(curr);
            return;
        }
        helper(n, curr + '0',str);
        helper(n, curr + '1',str);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string>str;
        unordered_set<string> given(nums.begin(), nums.end());
        helper(n, "",str);
        for (const string &s :str) {
            if (given.find(s) == given.end()) {
                return s;
            }
        }
        return "";
    }
};
