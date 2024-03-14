class Solution {
public:

    void dfs(int row, int col, vector<vector<char>>& grid, int n, int m){
        grid[row][col] = '0';
        vector<int> dr = {-1,0,+1,0};
        vector<int> dc = {0,-1,0,+1};

        for(int i=0 ; i<4 ; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == '1'){
                dfs(nr, nc, grid, n, m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == '1'){
                    dfs(i, j ,grid, n, m);
                    count++;
                }
            }
        } 
        return count;       
    }
};