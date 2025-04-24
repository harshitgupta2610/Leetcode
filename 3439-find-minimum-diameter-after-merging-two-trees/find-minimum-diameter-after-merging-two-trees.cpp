class Solution {
public:
    int n ;
    pair<int,int> BFS(unordered_map<int,vector<int>> &adj,int source){
        queue<int> que;
        que.push(source);

        unordered_map<int, bool> visited;
        visited[source] = true;

        int distance = 0;
        int farthestNode = source;

        while(!que.empty()) {
            int size = que.size(); //current level me itne nodes hain

            while(size--) {
                int curr = que.front();
                que.pop();

                farthestNode = curr;

                for(auto &nbr : adj[curr]) {
                    if(visited[nbr] == false) {
                        visited[nbr] = true;
                        que.push(nbr);
                    }
                }
            }
            if(!que.empty()) {
                distance++;
            }
        }

        return {farthestNode, distance};

    }
    unordered_map<int,vector<int>> build(vector<vector<int>> &edges){
        unordered_map<int,vector<int>> adj;
        for(auto &vec :edges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    int find(unordered_map<int,vector<int>> &adj){
        auto [farthest , dist]= BFS(adj,0);

        auto [otherend , diameter]= BFS(adj,farthest);

        return diameter;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>> adj1 = build(edges1);
        unordered_map<int,vector<int>> adj2 = build(edges2);

        int d1 = find(adj1);
        int d2 = find(adj2);

        int c = (d1+1)/2 + (d2+1)/2 + 1;

        return max({c,d1,d2});
    }
};