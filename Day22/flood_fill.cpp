class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size(), m = image[0].size(); 
        vector<vector<int>> temp = image; 
        queue<pair<int,int>> q ;
        q.push({sr, sc});
        int prevColor = image[sr][sc] ;

        vector<int> dr = {-1,0,+1,0};
        vector<int> dc = {0,-1,0,+1};

        while(!q.empty()){
            auto nodex = q.front().first;
            auto nodey = q.front().second;
            q.pop() ;

            temp[nodex][nodey] = color;

            for(int i=0 ; i<4 ; i++){
                int nr = nodex + dr[i];
                int nc = nodey + dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m && temp[nr][nc] == prevColor && temp[nr][nc] != color){
                    q.push({nr, nc});
                }
            }
        }
        return temp;
    }
};