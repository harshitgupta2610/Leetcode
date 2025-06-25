class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n =nums.size();
        map<int,int> mp;
        for(int i =0;i<n;i++){
            mp[nums[i]]++;
        }
        int dup =0;
        int mis =0;
        for(int i =1;i<=n;i++){
            if(mp.count(i)){
                if(mp[i]==2){
                    dup = i;
                }
            }
            else{
                mis=i;
            }
        }
        return {dup,mis};
    }
};