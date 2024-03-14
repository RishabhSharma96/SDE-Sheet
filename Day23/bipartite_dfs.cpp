class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph, int color, vector<int> & colors){
        colors[node] = color;
        
        for(auto it : graph[node]){
            if(colors[it] == color){
                return false;
            }
            else if(colors[it] == -1){
                if(dfs(it, graph, !color, colors) == false){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size() ;
        vector<int> colors(n,-1);
        
        for(int i=0 ; i<graph.size() ; i++){
            if(colors[i] == -1){
                if(dfs(i, graph, 0, colors) == false){
                    return false;
                }
            }
        }
        return true;
    }
};