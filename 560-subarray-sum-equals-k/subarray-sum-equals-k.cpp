class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int,int> mp;
        int result =0;
        int currsum=0;
        mp[0]=1;
        for( int  &num : nums){
            currsum+= num;
            int rem = currsum - k;
            if(mp.find(rem)!= mp.end()){
                result += mp[rem];
            }
            mp[currsum]++;
        }
        return result;
        
    }
};
