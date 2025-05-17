class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int gasc=0;
        int costc=0;
        for(int i =0;i<n;i++){
            gasc+=gas[i];
            costc+=cost[i];
        }
        if(gasc<costc){
            return -1;
        }
        int res = 0;
        int total=0;

        for(int i =0 ;i<n;i++){
            total += gas[i]-cost[i];
            if(total<0){
                res = i+1;
                total =0;
            }
        }
        return res;
    }
};