class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      //shortes distance in undirected graph 
        //make a vector to store the distance initilize it with INT_MAX
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX-100000));
        //queue data structure to store the node and its weight
        queue<pair<int,int>>q;
        //filling the q with the node having 0 means it doesn need to go min distance is 0 to go to 0
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dist[i][j]=0;
                }
            }
        }
        int di[4]={-1,0,+1,0};
        int dj[4]={0,+1,0,-1};
      while(!q.empty()){
          pair<int,int>a=q.front();
          q.pop();
          int i=a.first;
          int j=a.second;
          for(int ind=0;ind<4;ind++){
              int ni=i+di[ind];
              int nj=j+dj[ind];
            if(ni>=0 && nj>=0 && ni<n && nj<m)
              if(dist[ni][nj]>dist[i][j]+1){
                  dist[ni][nj]=dist[i][j]+1;
                  q.push({ni,nj});
              }
          }
      }
        return dist;
    }
};




