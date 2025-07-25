class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int i = 0, j = 0;
        string result;
        while (i < n) {
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;
            int start = i;
            while (i < n && s[i] != ' ') i++;
            int end = i;
            reverse(s.begin() + start, s.begin() + end);
            if (!result.empty()) result += ' ';
            result += s.substr(start, end - start);
        }

        return result;
    }
};
