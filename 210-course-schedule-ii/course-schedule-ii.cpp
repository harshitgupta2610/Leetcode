class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& mp) {
        unordered_map<int,vector<int>>adj;
        vector<int> indegree(n);
        vector<int> result;
         for(auto i :mp ){
            int x= i[0];
            int y = i[1];
            adj[y].push_back(x);
            indegree[x]++;
        }
        queue<int> que;
        for(int i =0 ;i <n;i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int curr = que.front();
            result.push_back(curr);
            que.pop();
            for(int &v : adj[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    que.push(v);
                }
            }
        }
        if (result.size()!=n) {
            return {};
        }
        return result;
    }
};