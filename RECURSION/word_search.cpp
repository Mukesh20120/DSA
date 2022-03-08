class Solution {
    private:
    int visit[7][7];
public:
    bool dfs(vector<vector<char>>&board,string word,int i,int j,int row,int col,int cur){
        //base case when check all the element
        if(cur==word.length())return true;
        //boundary case
        if(i<0 || j<0 || i>=row || j>=col || board[i][j]!=word[cur] || visit[i][j])return false;
        //marking visited
        visit[i][j]=1;
        bool result=(dfs(board,word,i-1,j,row,col,cur+1) ||
                     dfs(board,word,i,j+1,row,col,cur+1) ||
                     dfs(board,word,i+1,j,row,col,cur+1) ||
                    dfs(board,word,i,j-1,row,col,cur+1));
        //marking 0 again when returning
        visit[i][j]=0;
        return result;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        memset(visit,0,sizeof(visit));
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(word[0]==board[i][j] && dfs(board,word,i,j,row,col,0))
                    return true;
            }
        }
        return false;
    }
};