class Solution {
public:
    bool dfs(vector<vector<int>>& graph ,int curr, vector<int> &color, int currcolor){
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
    // bool isBipartite(vector<vector<int>>& graph) {
    //     int u = graph.size();
    //     vector<int> color (u,-1);
    //     int currcolor=1;
    //     for(int i =0 ;i<u;i++){
    //         if(color[i]==-1){
    //             if(!bfs(graph,i,color,currcolor)){
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }

    //bfs
    bool bfs(vector<vector<int>>& graph ,int curr, vector<int> &color, int currcolor){
        color[curr]= currcolor;
        queue<int> q;
        q.push(curr);
        int colorOfV;
        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(int &v:graph[u]){
                if(color[v]==color[u]){
                    return false;
                }
                else if(color[v] == -1){
                    if(color[u]==0){
                        color[v]=1;
                    }
                    else{
                        color[v]=0;
                    }
                    q.push(v);
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
                if(!bfs(graph,i,color,currcolor)){
                    return false;
                }
            }
        }
        return true;
    }
};