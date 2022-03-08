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

//2nd method we don't need extra space we can use original 2d matrix

class Solution {
public:
    bool dfs(vector<vector<char>>&board,string &word,int i,int j,int cur){
      if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
          return false;
      if(board[i][j]!=word[cur])
          return false;
    
         if(cur==word.length()-1)return true;
        char c=board[i][j];
        board[i][j]='0';
        bool result=(dfs(board,word,i-1,j,cur+1) ||
                     dfs(board,word,i,j+1,cur+1) ||
                     dfs(board,word,i+1,j,cur+1) ||
                    dfs(board,word,i,j-1,cur+1));
       
         board[i][j]=c;
        return result;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
      
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
               bool flag=dfs(board,word,i,j,0);
                if(flag)
                    return true;
            }
        }
        return false;
    }
};