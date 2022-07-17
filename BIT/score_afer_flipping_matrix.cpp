class Solution {
    private:
    int n,m;
public:
    void fliprow(vector<vector<int>>&grid,int i){
        for(int j=0;j<m;j++){
            grid[i][j]=(!grid[i][j]);
        }
    }
     void flipcol(vector<vector<int>>&grid,int j){
        for(int i=0;i<n;i++){
            grid[i][j]=(!grid[i][j]);
        }
    }
    
    int matrixScore(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        
        for(int i=0;i<n;i++){
            if(!grid[i][0])
                fliprow(grid,i);
        }
       
       for(int j=1;j<m;j++){
           int z=0;
           for(int i=0;i<n;i++){
               if(!grid[i][j])
                   z++;
           }
           if(z>n-z)
               flipcol(grid,j);
       }
      
        long sum=0;
        for(int i=0;i<n;i++){
            long t=0;
            for(int j=m-1;j>=0;j--){
            if(grid[i][j])
                t=t|(1<<(m-j-1));
            }
            sum+=t;
        }
        
        return (int)sum;
    }
};