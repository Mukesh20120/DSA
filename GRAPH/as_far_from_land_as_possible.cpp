class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
       //doesn't required adj matrix we can use grid
        int n=grid.size();
      vector<vector<int>>dist(n,vector<int>(n,1e4));
      //question boil down to find the shortest distance from land
       //queue data sturcture to store the cordinates of index
        queue<pair<int,int>>q;
        
        //filling the queue with land 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        int maxi=-1;
        int di[]={-1,0,+1,0};
        int dj[]={0,+1,0,-1};
        while(!q.empty()){
           pair<int,int>temp=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int ni=temp.first+di[i];
                int nj=temp.second+dj[i];
                if(ni>=0 && nj>=0 && ni<n && nj<n){ 
               int nd=abs(temp.first-ni)+abs(temp.second-nj)+dist[temp.first][temp.second];
                if(dist[ni][nj]>nd){
                    dist[ni][nj]=nd;
                    q.push({ni,nj});
                    maxi=max(maxi,nd);
                }
                }
            }
        }
       }         
        return maxi;
    }
};