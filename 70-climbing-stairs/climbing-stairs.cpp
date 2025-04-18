class Solution {
public:
    int helper(vector<int> &temp,int n){
        if(n<0){return 0;}
        if(n==0){return 1;}
        if(temp[n] != -1){
            return temp[n];
        }
        return temp[n]= helper(temp,n-1) + helper(temp,n-2);
    }
    int climbStairs(int n) {
        vector<int> temp(n+1,-1);
        return helper(temp,n);
    }
};