class Solution {
public:
    
    bool check(vector<vector<char>>& board, int row, int col, char num){

        for(int i=0; i<board.size() ; i++){
            if(board[row][i] == num){
                return false;
            }
        }

        for(int i=0; i<board.size() ; i++){
            if(board[i][col] == num){
                return false;
            }
        }

        for(int i=0; i<board.size() ; i++){
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == num){
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board){

        for(int row=0 ; row<board.size() ; row++){
            for(int col=0 ; col<board[0].size() ; col++){

                if(board[row][col] == '.'){

                    for(char number='1' ; number<='9' ; number++){

                        if(check(board,row,col,number)){
                            board[row][col] = number ;

                            if(solve(board)){
                                return true ;
                            }
                            else{
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) { 
        solve(board); 
    }
};