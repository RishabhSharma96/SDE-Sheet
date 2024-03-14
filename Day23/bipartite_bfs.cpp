class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> colors(n, -1);
        queue<pair<int,int>> q ;

        for(int i=0 ; i<n ; i++){
            if(colors[i] == -1){
                q.push({i,0});

                while(!q.empty()){
                    auto node = q.front().first ;
                    auto color = q.front().second ;
                    q.pop();

                    colors[node] = color;

                    for(auto it : graph[node]){
                        if(colors[it] == color){
                            return false;
                        }
                        else if(colors[it] == -1){
                            q.push({it, !color});
                        }
                    }
                }
            }
        }
        return true;
    }
};