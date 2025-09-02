class Solution {
public:
    bool val(int r, int c,vector<vector<int>>& image, vector<vector<int>>& ans,int iniColor,
    int color) {

        int m = image.size();
        int n = image[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n){ 
            return false;
        }

        if (ans[r][c] == color) return false;                  // already painted [2]


        return image[r][c] == iniColor;                        // still initial color [1]
    }
    void dfs(int r, int c, vector<vector<int>>& image,vector<vector<int>>& ans,
    int iniColor, int color){

        ans[r][c]= color;

        int  m  = image.size();
        int n = image[0].size();

        if (val(r-1, c, image, ans, iniColor, color)){ 
            dfs(r-1, c, image, ans, iniColor, color); 
        }

        if (val(r, c+1, image, ans, iniColor, color)){ 
            dfs(r, c+1, image, ans, iniColor, color); 
        }


        if (val(r+1, c, image, ans, iniColor, color)){ 
            dfs(r+1, c, image, ans, iniColor, color); 
        }

        
        if (val(r, c-1, image, ans, iniColor, color)){ 
            dfs(r, c-1, image, ans, iniColor, color); 
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        
        dfs(sr,sc,image,ans,iniColor,color);
        return ans;
    }
};