class Solution {
public:
    bool bfs(unordered_map<int,vector<int>>&adj,int n ,vector<int> &indegree ){
        queue<int> que;
        int count =0 ;
        for(int i =0 ;i<n;i++){
            if(indegree[i]==0){
                count++;
                que.push(i);
            }
        }
        while(!que.empty()){
            int curr =  que.front();
            que.pop();
            for(int &v :adj[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    count++;
                    que.push(v);
                }
            }
        }
        if(count==n){
            return true;
        }
        return false;
    }
    // bool canFinish(int n, vector<vector<int>>& mp) {
    //     unordered_map<int,vector<int>>adj;
    //     vector<int> indegree(n+1);
    //     for(auto &vec:mp){
    //         int u =vec[0];
    //         int v =vec[1];
    //         adj[v].push_back(u);
    //         indegree[u]++;
    //     }
        
    //     return bfs(adj,n,indegree);
    // }
    bool dfs(unordered_map<int,vector<int>>&adj,int u ,vector<bool> &visit,vector<bool> &inrecur){
        visit[u]=true;
        inrecur[u]=true;

        for(int &v : adj[u]){
            if(!visit[v] && dfs(adj,v,visit,inrecur)){
                return true;
            }
            else if(inrecur[v]==true){
                return true;
            }
        }
        inrecur[u]=false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& mp) {
        unordered_map<int,vector<int>>adj;
        vector<bool> visit(n+1,false);
        vector<bool> inrecur(n+1,false);
        for(auto &vec:mp){
            int u =vec[0];
            int v =vec[1];
            adj[v].push_back(u);
        }
        for(int i =0 ;i<n;i++){
            if(!visit[i]&& dfs(adj,i,visit,inrecur)){
                return false;
            }
        }
        return true;
    }
};