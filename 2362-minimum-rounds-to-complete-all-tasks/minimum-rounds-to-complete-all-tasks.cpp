class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n =  tasks.size();
        int count =0;
        map<int,int> mp;
        for(int i =0;i<n;i++){
            mp[tasks[i]]++;
        }
        for (auto& [task, j] : mp) {
            if (j == 1) {
                return -1;
            }
            count+=(j+2)/3;
        }
        return count;
    }
};