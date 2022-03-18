class Solution {
    private:
    int count=0;
    int di[4]={-1,0,+1,0};
    int dj[4]={0,+1,0,-1};
public:
    void fun(int i,int j,vector<vector<int>>& grid){
        //boundary traver
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0){
                count++;
            return;
        }
     if(grid[i][j]==2)
         return;
        grid[i][j]=2;
        for(int ind=0;ind<4;ind++)
            fun(i+di[ind],j+dj[ind],grid);
            
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    fun(i,j,grid);
                    return count;
                }
            }
        }
        return count;
    }
};