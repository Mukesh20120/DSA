class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkcycle(int node,int prev,vector<int>&visit,vector<int>adj[]){
        //updating the first visiting element
        visit[node]=1;
        //traversing through given matrix perticular row
        for(auto it: adj[node]){
            //two case arise if not visited then check for cycle
            if(visit[it]==0){
                if(checkcycle(it,node,visit,adj))
                   return true;
            }
            //checking the parents is equal
            else if(it!=prev)
            return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        //vector to check visited element or not
       vector<int>visit(V,0);
       //loop for two or more unlinked graph
       for(int i=0;i<V;i++){
           if(visit[i]==0){
               if(checkcycle(i,-1,visit,adj))//gave if the graph have cycle or not
                 return true;
           }
       }
       return false;
    }
};