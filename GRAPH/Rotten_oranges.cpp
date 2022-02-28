//here x and y are the cordinate of the matrix
class node{
public:
    int x;
    int y;
    int time;

    node(int _x,int _y,int _time){
        x=_x;
        y=_y;
        time=_time;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //we do a bfs search of graph 
        queue<node>q;
        int countoranges=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //filling the queue with the rotton oranges for bfs traversal
                if(grid[i][j]==2)
                    q.push({i,j,0});
                //counting the number of total oranges in the grid
                if(grid[i][j]!=0)
                    countoranges++;
            }
        }
        //for traversal the up/right/down/left
        int dx[]={-1,0,+1,0};
        int dy[]={0,+1,0,-1};
        int ans=0;
        int cnt=0;
        while(!q.empty()){
            int xp=q.front().x;
            int yp=q.front().y;
            int time=q.front().time;
            q.pop();
            ans=max(ans,time);
            cnt++;
            for(int ind=0;ind<4;ind++){
                int s=xp+dx[ind];
                int e=yp+dy[ind];
                if(s>=0 && s<n && e>=0 && e<m && grid[s][e]==1){
                    grid[s][e]=2;
                    q.push({s,e,time+1});
                }
            }
        }
        //cnt and total number of oranges are same then it traversal all the node in graph
        //if not then it mean some oranges are not rotten they are beyond reach
        if(cnt==countoranges)
           return ans;
        return -1;
    }
};
