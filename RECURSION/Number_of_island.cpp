class Solution {
public:
    void markisland(vector<vector<char>>&grid,int i,int j,int row,int col){
        //base case checking outof boundary and if valid of not
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j]!='1')
            return;
        //changing all the connected to it
        grid[i][j]='0';
        
        //moving up/right/down/left 
        markisland(grid,i-1,j,row,col);
        markisland(grid,i,j+1,row,col);
        markisland(grid,i+1,j,row,col);
        markisland(grid,i,j-1,row,col);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int island=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                //if we found any island we make it 0 and move on
                if(grid[i][j]=='1'){
                markisland(grid,i,j,row,col);
                    island++; //how many island we encounter
                }
            }
        }
        return island;
    }
};