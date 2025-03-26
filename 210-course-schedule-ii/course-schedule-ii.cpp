class Solution {
public:
    //bfs
    // vector<int> findOrder(int n, vector<vector<int>>& mp) {
    //     unordered_map<int,vector<int>>adj;
    //     vector<int> indegree(n);
    //     vector<int> result;
    //      for(auto i :mp ){
    //         int x= i[0];
    //         int y = i[1];
    //         adj[y].push_back(x);
    //         indegree[x]++;
    //     }
    //     queue<int> que;
    //     for(int i =0 ;i <n;i++){
    //         if(indegree[i]==0){
    //             que.push(i);
    //         }
    //     }
    //     while(!que.empty()){
    //         int curr = que.front();
    //         result.push_back(curr);
    //         que.pop();
    //         for(int &v : adj[curr]){
    //             indegree[v]--;
    //             if(indegree[v]==0){
    //                 que.push(v);
    //             }
    //         }
    //     }
    //     if (result.size()!=n) {
    //         return {};
    //     }
    //     return result;
    // }

    bool check = false; 
    void dfs(unordered_map<int,vector<int>>&adj,int u,vector<bool> &visit,stack<int> &st,vector<bool>&inrecur){
        visit[u]=true;
        inrecur[u]=true;

        for(int &v : adj[u]){
            if(inrecur[v] == true) {
                check = true;
                return;
            }
            if(!visit[v]){
	            dfs(adj, v, visit, st, inrecur);
            }
        }
        st.push(u);
        inrecur[u] = false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& mp) {
        unordered_map<int,vector<int>>adj;
        vector<bool> visit(n);
        vector<bool> inrecur(n);
        stack<int> st ;
        vector<int> result;
        for(auto &i :mp ){
            int x = i[0];
            int y = i[1];
            adj[y].push_back(x);
        }
        check = false;
        for(int i =0 ;i <n;i++){
            if(!visit[i]){
                dfs(adj,i,visit,st,inrecur);
            }
        }
        if(check){
            return {};
        }
        
	    while(!st.empty()) {
	        result.push_back(st.top());
	        st.pop();
	    }
	    
	    return result;
    }
};