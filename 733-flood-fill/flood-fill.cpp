class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        int m = image.size(), n = image[0].size();

        int ini = image[sr][sc];

        if (ini == newColor) return image;          

        queue<pair<int,int>> q;

        q.push({sr, sc});

        image[sr][sc] = newColor;                             
        int dr[8] = {-1, 0, 1, 0};
        int dc[8] = {0, 1, 0, -1};

        while (!q.empty()) {

            auto [r, c] = q.front(); 
            
            q.pop();
            for (int k = 0; k < 4; k++) {                     

                int nr = r + dr[k], nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n   
                    && image[nr][nc] == ini) {                

                    image[nr][nc] = newColor;  

                    q.push({nr, nc});                        
                }
            }
        }
        return image;
    }
};