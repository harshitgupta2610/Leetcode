class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int,int> ind,outd;
        for(auto &vec:pairs){
            int u = vec[0];
            int v =vec[1];
            adj[u].push_back(v);
            outd[u]++;
            ind[v]++;
        }
        int start= pairs[0][0];
        for(auto &it: adj){
            int node = it.first;
            if(outd[node]-ind[node]==1){
                start =node;
                break;
            }
        }
        vector<int> result;
        stack<int> st;
        st.push(start);

        while(!st.empty()){
            int curr = st.top();
            if(!adj[curr].empty()){
                int neigh = adj[curr].back();
                adj[curr].pop_back();
                st.push(neigh);
            }
            else{
                result.push_back(curr);
                st.pop();
            }
        }
        reverse(result.begin(),result.end());
        vector<vector<int>> ans;
        for(int i =0;i<result.size()-1;i++){
            ans.push_back({result[i],result[i+1]});
        }
        return ans;
    }
};