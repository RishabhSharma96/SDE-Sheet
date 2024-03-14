class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool dfs(int node, int parent, vector<int>& visited, vector<int> adj[]){
        
        visited[node] = 1;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it, node, visited, adj);
            }
            else{
                if(it != parent){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        

        for(int i=0 ; i<V ; i++){
            
            vector<int> visited(V, 0);
            bool res = dfs(i, -1, visited, adj);
            if(res){
                return true;
            }
            
        }
        return false;
    }
};