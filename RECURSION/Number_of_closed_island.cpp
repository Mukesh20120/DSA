class Solution {
    int di[4]={-1,0,+1,0};
    int dj[4]={0,+1,0,-1};
public:
    void change(vector<vector<int>>&grid,int i,int j,int row,int col){
        //boundary check 
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j]!=0)
            return;
        grid[i][j]=2;
        for(int ind=0;ind<4;ind++){
            change(grid,i+di[ind],j+dj[ind],row,col);
        }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        //question is same as number of island what we will do
        // all the land connect to boundary can't be count because it not surround with water
        
        //makes every boundary connected land into water or any other value
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 || i==row-1){
                    if(grid[i][j]==0)
                        change(grid,i,j,row,col);
                }
                if(j==0 || j==col-1){
                    if(grid[i][j]==0)
                        change(grid,i,j,row,col);
                }
            }
        }
       //now we have to count the encounter 0 /land 
        int cnt=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0){
                    cnt++;
                    change(grid,i,j,row,col);
                }
            }
        }
          for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==2)
                  grid[i][j]=0;
            }
        }
        return cnt;
    }
};