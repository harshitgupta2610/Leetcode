class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rock, int ex) {
        int n = cap.size();
        int count =0;
        vector<int> ans(n);
        for(int i =0 ;i<n;i++){
            ans[i] = cap[i]-rock[i];
        }
        sort(ans.begin(),ans.end());
        for(int i =0 ;i<n;i++){
            if(ex>=ans[i]){
                ex-=ans[i];
                count++;
            }
            else{
                break;
            }
        }
        return count;
    }
};