class Solution {
public:
    int n;
    vector<vector<int>> directions {{0,1},{1,0},{0,-1},{-1,0}};
    bool helper(vector<vector<int>>& grid,int i, int j,int mid , vector<vector<bool>> &visited){
        if(i<0||i>=n||j<0||j>=n||visited[i][j]==true||grid[i][j]>mid){
            return false;
        }
        visited[i][j]=true;
        if(i==n-1 && j==n-1){
            return true;
        }
        for( auto &dir: directions ){
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            if(helper(grid,i_,j_,mid,visited)){
                return true;
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int left =grid[0][0];
        int right = n*n-1;
        int result =0;
  
          while(left<=right){
            int mid = left + (right - left)/2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if(helper(grid,0,0,mid,visited)){
                result =mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return result;
    }
};