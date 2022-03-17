class Solution {
    //making graph and ans global
    vector<pair<int,int>>adj[101];
    vector<pair<int,int>>ans;
public:
    bool static cmp(pair<int,int>a,pair<int,int>b){
        if(a.first!=b.first)
            return a.first<b.first;
        
        return a.second>b.second;
    }
    
    void dijastra(int scr,int n,int dt){
        //making a distance vector to store the minimum distance from the source
        vector<int>dist(n,INT_MAX);//initilized with maximum value
        
        //priority queue
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,scr});
        dist[scr]=0;
        
        while(!pq.empty()){
            int prev=pq.top().second;
            int prevdist=pq.top().first;
            pq.pop();
            for(auto it: adj[prev]){
                if(dist[it.first]> it.second+prevdist){
                    dist[it.first]=it.second+prevdist;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        
        //now dist vector filled we have to find the node have greater from dt
        int cnt=0;
       for(int i=0;i<n;i++)
           if(i!=scr && dt>=dist[i])
               cnt++;
    
       ans.push_back({cnt,scr});
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        //filling the graph
        for(int i=0;i<edges.size();i++){
            int u,v,w;
            u=edges[i][0]; //from
            v=edges[i][1]; //to
            w=edges[i][2]; //weight
            //node connect to node, its weight
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        //Dijastra check for all the given nodes
        for(int i=0;i<n;i++)
            dijastra(i,n,dt); //passing source,total no of nodes,distance threshold
        
        sort(ans.begin(),ans.end(),cmp);
        
        return ans[0].second;
    }
};