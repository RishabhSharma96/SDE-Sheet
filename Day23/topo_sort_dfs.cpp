class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void dfs(int node, stack<int> & s, vector<int> & visited, vector<int> adj[]){
        visited[node] = 1;
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it, s, visited, adj);
            }
        }
        s.push(node);
    }

    vector<int> topoSort(int V, vector<int> adj[]) 
    {
        stack<int> s;
        vector<int> visited(V, 0);
        
        for(int i=0 ; i<V; i++){
            if(!visited[i]){
                dfs(i, s, visited, adj);
            }
        }
        
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
	}
};