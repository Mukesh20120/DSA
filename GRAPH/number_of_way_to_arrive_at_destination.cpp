class Solution {
public:
    //define to make easy
    #define ll long long
    #define pll pair<ll,ll>
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        //we are getting from vector are node,node and time
        vector<pll>adj[n];
        //filling the adjacent vector or our graph
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        //a array for store number of ways
       vector<ll>ways(n,0);
        // a array of distance to store the distance as well as the ways above it alternative
      vector<ll>dist(n,1e18);
        
        //priority queue to get the minimum value each time
        priority_queue<pll,vector<pll>,greater<pll>>pq;
        //now we have to start from the starting node mark it ways and distance
        ways[0]=1;
        dist[0]=0;
        //pushing into the pq data structure
          //distance  and source as it sorted according to first value
        pq.push({0,0});
        while(!pq.empty()){
            pll temp=pq.top();
            pq.pop();
            //try all adjacent node of the source node
            for(auto it: adj[temp.second]){
                if(temp.first+it.second<dist[it.first]){
                    dist[it.first]=temp.first+it.second;
                    ways[it.first]=ways[temp.second];
                    pq.push({dist[it.first],it.first});
                }
                else if(temp.first+it.second==dist[it.first]){
                    ways[it.first]=(ways[it.first]+ways[temp.second])%mod;
                }
            }
        }
        return ways[n-1];
    }
};