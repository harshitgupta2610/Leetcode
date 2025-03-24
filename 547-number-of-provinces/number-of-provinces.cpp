class Solution {
public:
    int n ;
    void dfs(unordered_map <int, vector<int> > &adj,int u, vector<bool>&visit){
        visit[u]=true;
        for(int &v: adj[u]){
            if(!visit[v]){
                dfs(adj,v,visit);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        n =isConnected.size();

        unordered_map <int, vector<int> > adj;
        vector<bool> visit(n,false);
        for(int i =0 ;i <n; i++){
            for(int j =0 ;j <n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count =0;
        for(int i =0;i<n;i++){
            if(!visit[i]){
                count++;
                dfs(adj,i,visit);
            }
        }
        return count;
    }
};