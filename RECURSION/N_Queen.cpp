class Solution {
public:
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n,vector<int>&lr,vector<int>ld,
              vector<int>&uld){
        //base case check if col is outside the boundary
        if(col==n){
            ans.push_back(board);
            return;
        }
        
        //we run a loop from each row
        for(int row=0;row<n;row++){
            //checking the condition is it safe to put the Q at that position
        if(lr[row]==0 && ld[row+col]==0 && uld[n-1+col-row]==0){
            //if above condition is true then we update all of them
            lr[row]=1;
            ld[row+col]=1;
            uld[n-1+col-row]=1;
            board[col][row]='Q';
            //passing into the function for next column
            solve(col+1,board,ans,n,lr,ld,uld);
            //now we do backtracking
             lr[row]=0;
            ld[row+col]=0;
            uld[n-1+col-row]=0;
            board[col][row]='.';
        }
            
        }
        
        
    }
    
    vector<vector<string>> solveNQueens(int n) {
        //we make a 2d vector to store the answer
        vector<vector<string>>ans;
        //string for board vector
        string s(n,'.');
        //temporary vector board
        vector<string>board(n,s);
        //making hash for check three condition
        //1 check for each row
        //2 check for lowerdiagonal
        //3 check for upperleftdiagonal
        vector<int>lr(n,0),ld(2*n-1,0),uld(2*n-1,0);
        //passing into the function
        solve(0,board,ans,n,lr,ld,uld);
        return ans;
    }
};