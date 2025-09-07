class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        
            int x =-(n/2);
            int y = -x;

            for(int i = x ;i<=y;i++ ){
                if(i!=0){
                    res.push_back(i);
                }
            }
            if(n%2!=0){
                res.push_back(0);
            }
            return res;
    }
};