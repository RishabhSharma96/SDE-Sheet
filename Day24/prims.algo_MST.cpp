class Solution{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // for -> {weight, node}
                                                                            // if want mst then make for {weight, {node, parent}}
        vector<int> visited(V, 0);
        
        pq.push({0, 0});
        int sum = 0;
        
        while(!pq.empty()){
            auto node = pq.top().second;
            auto wt = pq.top().first;
            pq.pop();
            
            if(visited[node]){
                continue;
            }
            
            visited[node] = 1;
            sum += wt;
            
            for(auto it: adj[node]){
                
                int adjNode = it[0];
                int adjWeight = it[1];
                
                if(!visited[adjNode]){
                    pq.push({adjWeight, adjNode});
                }
                
            }
            
        }
        return sum;
    }
};