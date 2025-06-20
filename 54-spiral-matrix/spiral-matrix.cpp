class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        /*
        dir -0 left -right
        dir -1 top to bottom
        dir -2 right to left
        dir -3 bottom to top
        */

        vector<int> result ;
        int dir =0;
        int top =0;
        int bottom = m-1;
        int left =0;
        int right =n-1;

        while(top <= bottom && left <= right){
            if(dir == 0 ){
                //left  to right
                for(int i=left;i<=right;i++){
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dir == 1 ){
                //top to bottom
                for(int i=top;i<=bottom;i++){
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            else if(dir == 2 ){
                //right to left
                for(int i=right;i>=left;i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            else if(dir == 3){
                //bottom to top
                for(int i=bottom;i>=top;i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
            dir++;
            if(dir==4){
                dir=0;
            }
        }
        return result;
    }
};