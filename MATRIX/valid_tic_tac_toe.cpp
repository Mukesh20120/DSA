class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        //let firs check the count of x and 0
        int nx=0,no=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j]=='X')
                    nx++;
                else if(board[i][j]=='O')
                    no++;
            }
        }
        //this is valid case
        if(!(nx-no==1 || nx-no==0))
            return false;
        else if(nx==no){
            return !iswin(board,'X');
        }
        else{
            return !iswin(board,'O');
        }
        return false;
    }
    bool iswin(vector<string>&board,char c){
        //check for row
        for(int i=0;i<3;i++)
            if(board[i][0]==c && board[i][1]==c && board[i][2]==c)
                return true;
        //check col
        for(int j=0;j<3;j++)
            if(board[0][j]==c && board[1][j]==c && board[2][j]==c)
                return true;
        //check diagonal
        if(board[0][0]==c && board[1][1]==c && board[2][2]==c)
            return true;
        if(board[0][2]==c && board[1][1]==c && board[2][0]==c)
            return true;
        
        return false;
    }
};