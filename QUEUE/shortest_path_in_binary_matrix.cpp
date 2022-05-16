
class Solution {
    private:
    struct point{
    int x;
    int y;
    int cnt;
    };
    int dx[8]={-1,-1,0,1,1,1,0,-1};
    int dy[8]={0,1,1,1,0,-1,-1,-1};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //checking the top left and the bottom down cornor if it is 1 then ans is not possible
        if(grid[0][0] || grid[n-1][m-1])
            return -1;
        //making queue data structure
        queue<point>q;
        q.push({0,0,1});
        //marking the visited
        grid[0][0]=1;
        while(!q.empty()){
            point temp=q.front();
            q.pop();
            //checking it was the last stop
            if(temp.x==n-1 && temp.y==m-1)
                return temp.cnt;
            
            //running a loop and check for all 8 direction
            for(int i=0;i<8;i++){
                int a=temp.x+dx[i];
                int b=temp.y+dy[i];
                //checking base case
                if(a<n && a>=0 && b<m && b>=0 && grid[a][b]==0){
                    q.push({a,b,temp.cnt+1});
                    grid[a][b]=1;
                }
            }
        }
        return -1;
    }
};