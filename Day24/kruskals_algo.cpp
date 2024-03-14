class DisjointSet{
public:
    vector<int> parent;    
    vector<int> rank;
    vector<int> size;
    
    DisjointSet(int _size){
        parent.resize(_size+1, 0);
        rank.resize(_size+1, 0);
        size.resize(_size+1, 1);
        
        for(int i=0 ; i<=_size; i++){
            parent[i] = i;
        }
    }
    
    int findUltimateParent(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]); 
    }
    
    void unionByRank(int x, int y){
        int up_x = findUltimateParent(x);
        int up_y = findUltimateParent(y);
        
        if(up_x == up_y){
            return ;
        }
        
        if(rank[up_x] > rank[up_y]){
            parent[up_y] = up_x;
        }
        else if(rank[up_x] < rank[up_y]){
            parent[up_x] = up_y;
        }
        else{
            parent[up_x] = up_y;
            rank[up_x]++;
        }
    }
    
    void unionBySize(int x, int y){
        int up_x = findUltimateParent(x);
        int up_y = findUltimateParent(y);
        
        if(up_x == up_y){
            return ;
        }
        
        if(size[up_x] > size[up_y]){
            parent[up_y] = up_x;
            size[up_x] += size[up_y];
        }
        else{
            parent[up_x] = up_y;
            size[up_y] += size[up_x];
        }
    }
    
};

class Solution{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]){
        
        vector<pair<int,pair<int,int>>> edges;
        
        for(int i=0 ; i<V ; i++){
            for(auto it: adj[i]){
                int from = i ;
                int to = it[0];
                int wt = it[1];
                edges.push_back({wt, {from, to}});
            }
        }
        
        sort(edges.begin(), edges.end());
        int size=0 ;
        
        DisjointSet ds(V);
        
        for(auto it : edges){
            int from = it.second.first ;
            int to = it.second.second;
            int wt = it.first;
            
            if(ds.findUltimateParent(from) != ds.findUltimateParent(to)){
                size += wt;
                ds.unionByRank(from,to);
            }
        }
        return size;
    }
};