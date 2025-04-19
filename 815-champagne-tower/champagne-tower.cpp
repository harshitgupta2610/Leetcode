class Solution {
public:
    double t[101][101];
    double helper(int vol, int i, int j){
        if(i<0||j<0||i<j){
            return 0.0;
        }
        if(i==0 && j==0){
            return t[i][j] = vol;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        double left = (helper(vol,i-1,j-1)-1)/2.0;
        double right = (helper(vol,i-1,j)-1)/2.0;
        if(left<0){
            left =0.0;
        }
        if(right<0){
            right =0.0;
        }
        return t[i][j]= left +right;
    }
    double champagneTower(int vol, int i, int j) {
        for(int i = 0; i < 101;i++){
            for(int j =0;j<101;j++){
                t[i][j]=-1;
            }
        }
        return min(1.0,helper(vol,i,j));
    }
};