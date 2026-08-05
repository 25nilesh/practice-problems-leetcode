class Solution {
public: 
    void dfs(vector<vector<int>> &graph,int node,vector<bool>& visited,vector<bool>& suspicious){
        visited[node]=true;
        suspicious[node]=true;
        for(auto &ngbr:graph[node]){
            if(!visited[ngbr]){
                dfs(graph,ngbr,visited,suspicious);
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        vector<int> result;
        for(auto& edge: invocations){
            int u=edge[0];
            int v=edge[1];
            graph[u].push_back(v);
        }
        vector<bool> visited(n,false);
        vector<bool> suspicious(n,false);
        dfs(graph,k,visited,suspicious);
        
        for(auto& edge: invocations){
            int u=edge[0];
            int v=edge[1];
            if(!suspicious[u] && suspicious[v]){
                for(int i=0;i<n;i++){
                    result.push_back(i);
                }
                return result;
            }
        }

        for(int i=0;i<n;i++){
            if(!suspicious[i]) result.push_back(i);
        }
        return result;
    }
};