class Solution {
public:
    vector<int> countSort(vector<int>& nums) {
        if (nums.empty()) return {};
        
        int max = *std::max_element(nums.begin(), nums.end());
        vector<int> freq(max + 1, 0);
        
        for (int num : nums) {
            freq[num]++;
        }
        
        for (int i = 1; i < freq.size(); i++) {
            freq[i] += freq[i - 1];
        }
        vector<int> ans(nums.size());
        for (int num : nums) {
            ans[--freq[num]] = num;
        }
        
        return ans;
    }
    int maxIceCream(vector<int>& cost, int coins) {
        vector<int> costs = countSort(cost);
        int n =costs.size();
        int count =0;
        for(int i=0;i<n;i++){
            if(costs[i]>coins){
                return count;
            }
            else{
                count++;
                coins-=costs[i];
            }
        }
        return count;
    }
};