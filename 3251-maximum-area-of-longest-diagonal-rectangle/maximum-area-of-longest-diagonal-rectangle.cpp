class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int maxArea = 0;
        int maxDiagonal =0;
        for(auto &arr : dimensions){
            int x = arr[0];  
            int y = arr[1];
            int area = x*y;
            int diagonal = (x*x)+(y*y);
            if(diagonal>maxDiagonal){
                maxDiagonal = diagonal;
                maxArea = area;
            }else if (diagonal == maxDiagonal) {
                if (area > maxArea) maxArea = area;
            }
        }
        return maxArea;
    }
};