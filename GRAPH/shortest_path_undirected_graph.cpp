vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
      // as we know  n is the number of vertices and the m is number of edges
      //we make a graph 
      vector<int>adj[n+1];
      
      //filling the graph
      for(int i=0;i<m;i++)
        adj[edges[i][0]].push_back(edges[i][1]);
    
    //make a vector to store the distance initilized with -1
    vector<int>dis(n+1);
    
    //filling dis with max value
    for(int i=0;i<=n;i++)
    dis[i]=INT_MAX;
    
    //as we have given the source s
    dis[s]=0;//as we required the 0 distance to go to s
    
    //queue data structure for BFS traversal
    queue<int>q;
    q.push(s); 
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int it: adj[x]){
            //checking if the new value is smaller then previous store distance we 
            //update it and push it into the queue
            if(dis[x]+6<dis[it] ){
                dis[it]=dis[x]+6;
                q.push(it);
            }
        }
    }
    }