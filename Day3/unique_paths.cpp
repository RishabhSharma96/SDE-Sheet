class Solution {
public:

    int memo(int row, int col, vector<vector<int>> & dp){
        if(row == 0 || col == 0){
            return 1;
        }

        if(row<0 || col<0){
            return 0;
        }

        if(dp[row][col] != -1){
            return dp[row][col];
        }

        int up = 0;
        if(row>0){
            up = memo(row-1,col,dp);
        }

        int left = 0;
        if(col>0){
            left = memo(row,col-1,dp);
        }

        return dp[row][col] = (up+left);
    }

    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp (m , vector<int>(n , -1));
        // return memo(m-1,n-1,dp);

        vector<vector<int>> dp (m , vector<int>(n , 0));

        dp[0][0] = 1 ;

        for(int row=0 ; row<m ; row++){
            for(int col=0 ; col<n ; col++){

                if(row==0 && col==0){
                    continue ;
                }

                int up = 0;
                if(row>0){
                    up = dp[row-1][col];
                }

                int left = 0;
                if(col>0){
                    left = dp[row][col-1];
                }

                dp[row][col] = (up+left);
            }
        }

        return dp[m-1][n-1];
    }
};