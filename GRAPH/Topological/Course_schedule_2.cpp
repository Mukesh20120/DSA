class Solution {
public:
    void dfs(int i,vector<int>&visit,vector<int>&ans,vector<int>adj[]){
        //marking the visited in the visit array
        visit[i]=1;
        for(auto it: adj[i]){
            if(visit[it]==0)
                dfs(it,visit,ans,adj);
        }
        ans.push_back(i);
    }
    bool dfscycle(int i,vector<int>&visit,vector<int>&path,vector<int>adj[]){
        visit[i]=1;
        path[i]=1;
        for(auto it: adj[i]){
            if(visit[it]==0){
                if(dfscycle(it,visit,path,adj))
                    return true;
            }
            else if(path[it]!=0)
                return true;
        }
        path[i]=0;
        return false;
    }
    
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        //we have to return topological order 
        //two method to do that 1 dfs and 2 kahn algorithm
        
        //again we have to make a graph from given 2d vector
        vector<int>adj[n];
        
        for(int i=0;i<pre.size();i++)
            adj[pre[i][0]].push_back(pre[i][1]);
         
        //dfs+visit take element of stack in vector form top to bottom
        vector<int>visit(n,0),ans,path(n,0);
        
        //check cyclic if cycle then return empty vector ans
        for(int i=0;i<n;i++){
            if(visit[i]==0)
                if(dfscycle(i,visit,path,adj))
                    return ans;//passing the node,visit,path,graph
        }
       
        for(int i=0;i<n;i++)
            visit[i]=0;
        
        for(int i=0;i<n;i++){
            if(visit[i]==0){
                dfs(i,visit,ans,adj);
            }
        } 
        return ans;
    }
};