
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n =nums.size();
        vector<int> v(n+1,0);
        for(int i=0;i<n;i++){
            v[nums[i]]++;
        }
        int mis =0;int dup =0;
        for(int i=1;i<v.size();i++){
            if(v[i]==2){
                dup = i;
            }
            if(v[i]==0){
                mis = i;
            }
        }
        return {dup,mis};
    }
}; 

