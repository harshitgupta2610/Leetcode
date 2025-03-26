class Solution {
public:
    //dfs code
    void dfs(unordered_map<int,vector<int>> &adj,int n ,vector<bool> &visit ){
        visit[n]=true;
        for(int &v:adj[n]){
            if(!visit[v]){
                dfs(adj,v,visit);
            }
        }
    }
    // int findCircleNum(vector<vector<int>>& mp) {
    //     int n = mp.size();
    //     unordered_map<int,vector<int>> adj;
    //     vector<bool> visit(n,false);
    //     for(int i =0 ;i <n;i++){
    //         for(int j =0 ; j <n;j++){
    //             if(mp[i][j]==1){
    //                 adj[i].push_back(j);
    //                 adj[j].push_back(i);
    //             }
    //         }
    //     }
    //     int count =0 ;
    //     for(int i =0 ;i <n;i++){
    //         if(!visit[i]){
    //             count++;
    //             dfs(adj,i,visit);
    //         }
    //     }
    //     return count;
    // }

    //bfs code
    void bfs(unordered_map<int, vector<int>> &adj,int u ,vector<bool > &visit){
        queue<int> que;
        que.push(u);
        visit[u]=true;

        while(!que.empty()){
            int curr = que.front();
            que.pop();

            for(int &v:adj[curr]){
                if(!visit[v]){
                    bfs(adj,v,visit);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& mp) {
        int n = mp.size();
        unordered_map<int, vector<int>> adj;
        vector<bool > visit(n,false);
        int count =0 ;

        for(int i =0 ;i <n;i++){
            for(int j =0 ;j<n;j++){
                if(mp[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        for(int i =0 ;i < n;i++){
            if(!visit[i]){
                count++;
                bfs(adj,i,visit);
            }
        }
        return count;
    }
};