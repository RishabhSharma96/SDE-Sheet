class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        queue<pair<int,int>> q; // for -> {node, parent}
        
        
        for(int i=0 ; i<V ; i++){
            
            vector<int> visited(V, 0);
            q.push({i,-1});
            visited[i] = 1;
            
            while(!q.empty()){
                auto node = q.front().first;
                auto parent = q.front().second;
                q.pop();
                
                for(auto it : adj[node]){
                    if(!visited[it]){
                        q.push({it, node});
                        visited[it] = 1;
                    }
                    else{
                        if(it != parent){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};