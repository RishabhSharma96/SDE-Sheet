class Solution {
    public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        
        vector<int> distance(V, 1e8);
        distance[S] = 0;
        
        for(int i=0 ; i<V-1 ; i++){
            for(auto it : edges){
                int from = it[0];
                int to = it[1];
                int wt = it[2];
                
                if(distance[from] != 1e8 && distance[from]+wt < distance[to]){
                    distance[to] = distance[from]+wt;
                }
            }
        }
        
        for(auto it : edges){
            int from = it[0];
            int to = it[1];
            int wt = it[2];
            
            if(distance[from] != 1e8 && distance[from]+wt < distance[to]){
                return {-1};
            }
        }
        return distance;
    }
};