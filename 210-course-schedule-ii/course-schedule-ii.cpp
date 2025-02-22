class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        queue<int> q;
        vector<vector<int>> adj(numCourses);
        vector<int> order;

        for(auto i :prerequisites ){
            int x= i[0];
            int y = i[1];
            adj[y].push_back(x);
            indegree[x]++;
        }
        for(int  i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            order.push_back(x); 
            q.pop();
            for(int i =0;i<adj[x].size();i++){
                indegree[adj[x][i]]--;
                if(indegree[adj[x][i]]==0){
                    q.push(adj[x][i]);
                }
            }
        }
        if (order.size() != numCourses) {
            return {};
        }
        return order;
    }
};