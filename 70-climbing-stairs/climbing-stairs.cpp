class Solution {
public:
    int t [50];
    int helper(int n){
       if(n==0 || n==1 || n==2){
        return n;
       }
       if(t[n]!=-1){
        return t[n];
       }
        return  t[n]=  helper(n-1) +helper(n-2);
    }
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return helper(n);
    }
};