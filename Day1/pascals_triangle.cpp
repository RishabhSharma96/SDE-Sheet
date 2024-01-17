class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> pt ;

        for(int i=0; i<numRows; i++){
            vector<int> oneRow ;
            if(i == 0){
                oneRow.push_back(1);
                pt.push_back(oneRow);
                continue;
            }
            oneRow.push_back(1);
            for(int j=1; j<i; j++){
                oneRow.push_back(pt[i-1][j-1] + pt[i-1][j]);
            }
            oneRow.push_back(1);
            pt.push_back(oneRow);
        }
        return pt; 
    }
};