class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long n1 = n;
        if (n1 < 0) {
            x = 1 / x;
            n1 = -n1;
        }
        while(n1>0) {
            if(n1%2==1) {
                ans *= x;
                n1 -= 1;
            } else {
                x *= x;
                n1 /= 2;
            }
        }
        return ans;
    }
};
