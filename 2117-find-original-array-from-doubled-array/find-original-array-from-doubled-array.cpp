class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2!=0){
            return {};
        }
        sort(changed.begin(),changed.end());
        vector<int> result;
        map<int,int> mp;
        for(int i =0;i<n;i++){
            mp[changed[i]]++;
        }

        for(int &num : changed){
            int x = num*2;
            if(mp[num]==0){
                continue;
            }
            if(mp.find(x)==mp.end()||mp[x]==0){
                return{};
            }
            result.push_back(num);
            mp[num]--;
            mp[x]--;
        }
        return result;
    }
};