class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //make a adj of graph
        vector<pair<int,int>>adj[n+1];
        //filling the adj graph
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        //to maintain the distance from given nodes
        vector<int>dist(n+1,INT_MAX);
        //queue data structure to bfs traversal
        queue<int>q;
        //marking the given node distance and pushing into the queue
        dist[k]=0;
        q.push(k);
        while(!q.empty()){
            int ind=q.front();
            q.pop();
            for(auto it: adj[ind]){
                if(dist[it.first]>dist[ind]+it.second){
                    dist[it.first]=dist[ind]+it.second;
                    q.push(it.first);
                }
            }
        }
        int cnt=-1;
        for(int i=1;i<=n;i++){
          //  cout<<dist[i]<<" ";
            if(dist[i]==INT_MAX)
                return -1;
           cnt=max(cnt,dist[i]);
        }
        return cnt;
    }
};