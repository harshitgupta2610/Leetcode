class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        unordered_set<int> st;
        int count = 0;
        for (int i = 0; i < n; i++) {
            bool placed = false;
            for (int j = 0; j < n; j++) {
                if (st.find(j) == st.end() && baskets[j] >= fruits[i]) {
                    st.insert(j);
                    placed = true;
                    break;
                }
            }
            if (!placed) {
             count++;
            }
        }

        return count;
    }
};