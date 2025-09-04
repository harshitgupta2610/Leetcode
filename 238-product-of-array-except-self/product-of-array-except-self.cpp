class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        int count  =0;
        vector<int> res;
        for(int i =0;i<n;i++){
            if(nums[i]!=0){
                prod*=nums[i];
            }
            else{
                count++;
            }
        }
        for(int i =0;i<n;i++){
            if(count==1){
                if(nums[i]!=0){
                    res.push_back(0);
                }
                else{
                    res.push_back(prod);
                }
            }
            else if(count==0){
                res.push_back(prod/nums[i]);
            }
            else{
                res.push_back(0);
            }
            
        }
        return res;
    }
};