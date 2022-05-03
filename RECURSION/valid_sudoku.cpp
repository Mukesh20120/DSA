class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       return solve(board);
    }
    bool solve(vector<vector<char>>&board){
        //step 1 traverse through the matrix find empty space to fill
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j] != '.')
                 if(!isvalid(board, i, j, board[i][j]))
                       return false;
            }
        }
        return true;
    }
    bool isvalid(vector<vector<char>>&board,int row,int col,char c){
        
        for(int i=0;i<9;i++){
            if(i!=col && board[row][i]==c)
                return false;
            if(i!=row && board[i][col]==c)
                return false;
            int a=3*(row/3)+i/3;
            int b=3*(col/3)+i%3;
            if(row!=a && col!=b && board[a][b]==c)
                return false;
        }
        return true;
    }
};