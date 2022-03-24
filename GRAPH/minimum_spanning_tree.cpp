// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       //as we getting the graph 
     
       //step 1 make three array for key mst and parents
       int key[V];
       bool mst[V];
       int parents[V];
       //step 2 initilized it key with intmax mst with false and parents with -1;
       for(int i=0;i<V;i++){
           key[i]=INT_MAX;
           mst[i]=false;
           parents[i]=-1;
       }
       
      key[0]=0;
      
       //step 3 run loop for n node in graph
       for(int c=0;c<V;c++){
           
           //finding the minimum value in
           int mini=INT_MAX,u; //one for store the key value and 
           //other for index
           for(int v=0;v<V;v++){
               if(mst[v]==false && key[v]<mini){
                   mini=key[v]; //taking the minimum 
                   u=v; //storing the node
               }
           }
           mst[u]=true;
           //now we get the minimum and node take all it connecting
           //node in the array so we take our next node
           for(auto it: adj[u]){
               int n=it[0];
               int w=it[1];
               if(mst[n]==false && w<key[n]){
                   key[n]=w;
                   parents[n]=u;
               }
           }
       }
       int ans=0;
       for(int i=0;i<V;i++)
       ans+=key[i];
       
       return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends


//2nd method prims algo optimized version using priority queue
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {     bool visit[V]={false};
          vector<int>key(V,INT_MAX);
          int ans=0;
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
           pq.push({0,0});
           key[0]=0;
           while(!pq.empty()){
               int u=pq.top().second;
               int k=pq.top().first;
               pq.pop();
               visit[u]=true;
           for(auto it: adj[u]){
               int n=it[0];
               int w=it[1];
               if(visit[n]==false && w<key[n]){
                   key[n]=w;
                   pq.push({w,n});
               }
           }
         }
         for(int sum: key)
            ans+=sum;
       return ans;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends