class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int x =0;int y =0;
        for(int i =0 ;i<nums.size();i++){
            if(nums[i]<0){
                y++;
            }
            else if (nums[i]>0){
                x++;
            }
        }
        int res = max(x,y);
        return res;
    }
};