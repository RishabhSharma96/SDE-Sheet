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