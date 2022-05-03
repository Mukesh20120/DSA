class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        //passing in function
       solve(board); 
        return;
    }
    bool solve(vector<vector<char>>&board){
        //we check for every box of  matrix
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                //if we encounter with . then we sove it
                if(board[i][j]=='.'){
                    //then the box can have value from 1 to 9 we check everycondition
                    for(int c='1';c<='9';c++){
                        if(checkboard(board,c,i,j)){
                            board[i][j]=c;
                            if(solve(board))
                                return true;
                            else
                                board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool checkboard(vector<vector<char>>&board,char c,int row,int col){
        //we check for each row ,col,3*3 box
        for(int i=0;i<9;i++){
            //check in column
            if(board[i][col]==c)
                return false;
            //check in row
            if(board[row][i]==c)
                return false;
            //checking in box
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
                return false;
        }
        return true;
    }
};