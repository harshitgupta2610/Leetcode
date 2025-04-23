class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    
    void  Union(int x, int y){
        int x_parent =  find(x);
        int y_parent = find(y);
        if(x_parent ==y_parent){
            return ;
        }
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    
    int kruskal(vector<vector<int>> &vec){
        int sum =0;
        for(auto &temp:vec){
            int u =temp[0];
            int v = temp[1];
            int wt = temp[2];
            
            int paru=find(u);
            int parv=find(v);
            if(paru!=parv){
                Union(u,v);
                sum+=wt;
            }
        }
        return sum;
    }
    // int prim(vector<vector<pair<int,int>>> &adj,int V){
    //     priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
    //     pq.push({0,0});
    //     vector<bool> isMST(V,false);
    //     int sum =0;
    //     while(!pq.empty()){
    //         auto p =pq.top();
    //         pq.pop();
    //         int wt =p.first;
    //         int node = p.second;

    //         if(isMST[node]==true){
    //             continue;
    //         }
    //         isMST[node]=true;
    //         sum +=wt;

    //         for (auto &[ne, newt] : adj[node]) {
    //             if (!isMST[ne]) {
    //                 pq.push({newt, ne});
    //             }
    //         }
    //     }
    //     return sum;
    // }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V =points.size();
        vector<vector<int>> adj;
        parent.resize(V);
        rank.resize(V,-1);
        
        for(int i =0;i<V;i++){
            parent[i]=i;
        }
        for(int i =0;i<V;i++){
            for(int j =i+1;j<V;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];

                int d = abs(x1-x2)+abs(y1-y2);

                adj.push_back({i,j,d});
            }
        }
        auto comp = [&](vector<int> &v1,vector<int> &v2){
            return v1[2]<v2[2];
        };
        
        sort(adj.begin(),adj.end(),comp);
        
        return kruskal(adj);
    }
};