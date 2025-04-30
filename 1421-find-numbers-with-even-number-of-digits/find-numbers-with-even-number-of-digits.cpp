class Solution {
public:
    int count;
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        
        int res =0;
        for(int i=0;i<n;i++){
            int x = nums[i];
            count =0;
            while(x){
                count++;
                x/=10;
            }
            if(count%2==0){
                res++;
            }
        }
        return res;
    }
};