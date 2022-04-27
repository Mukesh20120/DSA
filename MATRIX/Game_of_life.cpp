class Solution {
public:
    int countneighbour(vector<vector<int>>&temp,int a,int b,int n,int m){
        int cnt=0;
        //up,dia,right,right-dia,down,down-dia,left,up-dia
       int row[8]={-1,-1,0,1,1,1,0,-1};
        int col[8]={0, 1,1,1,0,-1,-1,-1};
        for(int i=0;i<8;i++){
            int r=a,c=b;
            r+=row[i];
            c+=col[i];
            if(r>=0 && r<n && c>=0 && c<m){
                cnt+=temp[r][c]==1?1:0;
            }
        }
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        //making a temproary vector 
        vector<vector<int>>temp;
        temp=board;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                cnt=countneighbour(temp,i,j,n,m);
                //here we have two case either it was live cell or it was dead cell
                if(board[i][j]==1){
                    if(cnt<2 || cnt>3)
                        board[i][j]=0;
                }
                 else
                        board[i][j]=cnt==3?1:0;
            }
        }
    }
};