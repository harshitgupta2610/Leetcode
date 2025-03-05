class Solution {
public:
    long long coloredCells(int n) {
        int c =1;
        long box =1;
        while(c<=n){
            box+=(4*(c-1));
            c++;
        }
        return box;
    }
};