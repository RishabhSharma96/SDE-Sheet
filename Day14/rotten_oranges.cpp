class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;

        vector<vector<int>> visited(n, vector<int>(m,0)) ;
        vector<int> deltaRow = {-1,0,1,0};
        vector<int> deltaCol = {0,1,0,-1};

        queue<pair<pair<int,int>,int>> q ;

        for(int i=0 ;i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0}) ;
                    visited[i][j] = 1 ;
                }
            }   
        }

        int time = 0 ;

        while(!q.empty()){
            int row = q.front().first.first ;
            int col = q.front().first.second ;
            int t = q.front().second ;
            q.pop(); 

            time = max(time,t) ;

            for(int i=0 ; i<4 ; i++){
                int nr = row+deltaRow[i] ;
                int nc = col+deltaCol[i] ;

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1 
                && visited[nr][nc] != 1){
                    q.push({{nr,nc},t+1}) ;
                    visited[nr][nc] = 1 ;
                }
            }
        }

        for(int i=0 ;i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    return -1 ;
                }
            }   
        }

        return time ;
    }
};