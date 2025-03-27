class Solution {
public:
    bool dfs(vector<vector<int>>& graph ,int curr, vector<int> &color, int currcolor){
        // queue<int> q;
        // q.push(curr);
        // color[curr]= currcolor;
        // while(!q.empty()){
        //     int p=q.front();
        //     q.pop();

        //     for(int &v:graph[p]){
        //         if(color[v]==color[p]){
        //             return false;
        //         }
        //         else if(color[v] == -1){
        //             color[v]=1- color[p];
        //             q.push(v);
        //         }
        //     }
        // }
        // return true;
        color[curr]=currcolor;
        int colorOfV;
        for(int &v:graph[curr]){
            if(color[v]==color[curr]){
                return false;
            }
            if(color[v]==-1){
                colorOfV = 1 - currcolor;
            
            if(!dfs(graph,v,color,colorOfV)){
                return false;
            }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int u = graph.size();
        vector<int> color (u,-1);
        int currcolor=1;
        for(int i =0 ;i<u;i++){
            if(color[i]==-1){
                if(!dfs(graph,i,color,currcolor)){
                    return false;
                }
            }
        }
        return true;
    }
};