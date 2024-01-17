class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size() ;

        for(int i=0 ; i<n ; i++){
            int ttd=0, btu=n-1;
            while(ttd < btu){
                swap(matrix[ttd][i] , matrix[btu][i]);
                ttd++;
                btu--;
            }
        }

        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }

    }
};