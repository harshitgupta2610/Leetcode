class Solution {
public:
     void dfs(vector<vector<int>>& image, int i, int j,int iniColor, int newColor){
        int m = image.size();
        int n = image[0].size();
        if(i<0 || i>=m || j<0 || j>=n || image[i][j] == newColor || image[i][j] != iniColor){
            return;
        }
        image[i][j] = newColor;
        dfs(image,i-1,j,iniColor,newColor);
        dfs(image,i+1,j,iniColor,newColor);
        dfs(image,i,j-1,iniColor,newColor);
        dfs(image,i,j+1,iniColor,newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        int iniColor = image[sr][sc];
        dfs(image,sr,sc,iniColor,newColor);
        return image;
    }
};