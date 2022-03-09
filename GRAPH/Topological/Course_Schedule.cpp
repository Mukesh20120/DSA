class Solution {
public:
    bool dfs(int i,vector<int>&visit,vector<int>&path,vector<int> adj[]){
        //marking the visited and the path 
        visit[i]=1;
        path[i]=1;
        
        //dfs all the node of the given node
        for(auto it: adj[i]){
            //if not visited then move to the that node by dfs
            if(visit[it]==0){
                if(dfs(it,visit,path,adj))
                     return true;
            }
            else if(path[it]!=0)
                return true;
        }
        //backtracking the path marking again 0
        path[i]=0;
        //all the above loop done and not able to return any thing then it is not cycle
        return false;
    }
    
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        //making two vector one for marking visited and other is to sotre the path
        vector<int>visit(n,0),visit_path(n,0);
        
        //we have given a 2d vector we need to make it adjancy list
        vector<int> adj[n];
        
        //filling the adjancy array that we made 
        for(auto it: pre){
            adj[it[0]].push_back(it[1]);
        }
        
        //use any one 
        //other way of filling using two for loop


        //  for(int i=0;i<pre.size();i++){
        //         adj[pre[i][0]].push_back(pre[i][1]);
        // }
        
        
        //now check for cycle in the graph we made above simple dfs
        for(int i=0;i<n;i++){
          //checking if not visited then pass to check cycle  
             if(visit[i]==0){  
               //checking the cycle passing starting node,visit,path,graph
            if(dfs(i,visit,visit_path,adj))
                    return false;
            }
        }
        //if cycle not found then it mean it can be a topological sort
        return true;
    }
};