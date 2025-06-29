class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m =grid.size();
        int n =grid[0].size();
        vector<int> result;
        
        for(int ball =0;ball<n;ball++){
            bool stop = false;
            int row =0;
            int col =ball;
            while(row<m && col<n){
                if(grid[row][col]==1){
                    if(col==n-1 || grid[row][col+1]==-1){
                        stop=true;
                        break;
                    }
                    col++;
                }
                else{
                    if(col== 0 || grid[row][col-1]==1){
                        stop=true;
                        break;
                    }
                    col--;
                }
                row++;
            }
            if(stop==true){
                result.push_back(-1);
            }
            else{
                result.push_back(col);
            }
        }
        return result;
    }
};