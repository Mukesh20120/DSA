class Solution {
public:
    void change(vector<vector<int>>&grid,int i,int j,int row,int col){
        //boundary check
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j]!=1)
            return;
        //marking visited
        grid[i][j]=2;
        
        //traversing in four direction up/right/down/left
        change(grid,i-1,j,row,col);
        change(grid,i,j+1,row,col);
        change(grid,i+1,j,row,col);
        change(grid,i,j-1,row,col);
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        //boundary traversal changing all the boundary connected to 2
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(i==0 || i==n-1){
               if(grid[i][j]==1)
                   change(grid,i,j,n,m);
           }
          if(j==0 || j==m-1){
              if(grid[i][j]==1)
                  change(grid,i,j,n,m);
          }
        }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    cnt++;
                if(grid[i][j]==2)
                    grid[i][j]=1;
              
            }
        }
        return cnt;
    }
};