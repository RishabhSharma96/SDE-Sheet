class Solution {
    public:

    bool solve(vector<int> adj[], int node, vector<int> & visited, vector<int> & pathVisited){
        visited[node] = 1 ;
        pathVisited[node] = 1 ;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                if(solve(adj,it,visited,pathVisited)){
                    return true ;
                } 
            }
            if(pathVisited[it]){
                return true ;
            }
        }
        pathVisited[node] = 0 ;
        return false ;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V,0) ;
        vector<int> pathVisited(V,0) ;
        
        for(int i=0 ; i<V ; i++){
            if(!visited[i]){
                if(solve(adj,i,visited,pathVisited)){
                    return true ;
                }
            }
        }
        return false ;
        
    }
};