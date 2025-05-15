class Solution {
public:
    int earliestFullBloom(vector<int>& plant, vector<int>& grow) {
        
        int n = plant.size();
        vector<pair<int, int>> vec(n);

        for(int i = 0; i<n; i++) {
            vec[i] = {plant[i], grow[i]};
        }

        auto lamva = [](pair<int,int> &p1 ,pair<int,int> &p2){
            return p1.second > p2.second;
        };
        sort(vec.begin(),vec.end(),lamva);
        int prev =0;
        int maxd =0;
        for(int i =0;i<n;i++){
            int currp = vec[i].first;
            int currg = vec[i].second;
            prev+=currp;
            int currplantbloom = prev+currg;
            maxd = max(maxd,currplantbloom);
        }
        return maxd;
    }
};