class Solution {
public:
    int partitionString(string s) {
        // int n = s.size();
        // unordered_map<int,int> mp;
        // for(int i =0;i<n;i++){
        //     mp[s[i]]++;
        // }
        // int max1=0;
        // for(auto &[prev,val]: mp){
        //     max1 = max(max1,val);
        // }
        // return max1;
        unordered_set<char> seen;
        int partitions = 1;

        for (char c : s) {
            if (seen.count(c)) {
                partitions++;
                seen.clear();
            }
            seen.insert(c);
        }

        return partitions;
    }
};