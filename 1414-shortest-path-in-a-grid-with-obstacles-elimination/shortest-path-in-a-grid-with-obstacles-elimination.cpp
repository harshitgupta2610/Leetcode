class Solution {
public:
vector<vector<int>> dirc{{-1,0},{1,0},{0,-1},{0,1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m =grid.size();
        int n = grid[0].size();
        queue<vector<int> > que;
        int i=0;int j=0;
        que.push({0,0,k});

        bool visited[41][41][1601];
        memset(visited,false,sizeof(visited));
        int steps =0;
        while(!que.empty()){
            int size = que.size();

            while(size--){
                vector<int> temp = que.front();
                que.pop();

                int curri = temp[0];
                int currj = temp[1];
                int obs = temp[2];

                if(curri == m-1 && currj == n-1){
                    return steps;
                }
                for(vector<int> &dir: dirc ){
                    int newi = curri+dir[0];
                    int newj = currj+dir[1];
                
                if(newi<0|| newi>=m||newj<0 || newj>=n){
                    continue;
                }

                 if(grid[newi][newj] == 0 && !visited[newi][newj][obs]) {
                        que.push({newi, newj, obs});
                        visited[newi][newj][obs] = true;
                } else if(grid[newi][newj] == 1 && obs > 0 && !visited[newi][newj][obs-1]) {
                        que.push({newi, newj, obs-1});
                        visited[newi][newj][obs-1] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};