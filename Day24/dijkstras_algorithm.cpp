class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> distance(V, INT_MAX);
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, S}); // for -> {distance, node}
        distance[S] = 0;
        
        while(!pq.empty()){
            
            auto node = pq.top().second;
            auto dist = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                if(dist + it[1] < distance[it[0]]){
                    pq.push({dist + it[1], it[0]});
                    distance[it[0]] = dist + it[1] ;
                }
            }
        }
        return distance;
    }
};