// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        //detecting cycle using kahn algorithm
        
        //step 1 make a vector of incoming nodes
        vector<int>incoming(V,0);
        //step 2 filling the incoming vector with count number of nodes incoming
        for(int i=0;i<V;i++){
            for(auto it: adj[i])
               incoming[it]++;
        }
        queue<int>q; //for BFS traverse
        //step 3 insert the nodes in queue which have 0 count 
        for(int i=0;i<V;i++)
            if(incoming[i]==0)
               q.push(i);
        //step 4 BFS traversal and a varible to count the node that entered in queue
        int cnt=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            cnt++;
            for(int it: adj[x]){
                incoming[it]--;
                if(incoming[it]==0)
                  q.push(it);
            }
        }
        //if total number of  cnt equal to V then its mean it have no cycle 
        if(cnt==V)return false;
        return true;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends