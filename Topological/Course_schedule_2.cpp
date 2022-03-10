/*
1 method using dfs
 steps 1 make a adjacent graph
 step 2 check if the graph have cycle or not 
 step 3 dfs traverse through graph and store in vector
*/

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



/* 2 method using kahn algorithm
step 1 make a graph from the given vector
step 2 check for the cycle if exist then return the empty vector
step 3 make a inorder vector store the number of incoming node in that node
step 4 make a queue and insert those whose inorder is 0
step 5 BFS traverse using queue
step 6 subtract inorder and if it inorder 0 push it into the queue
*/

class Solution {
public:
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
        //topological sort using bfs kahn algorithm
        //making vector to store the inorder
        vector<int>indegree(n,0);
        vector<int>adj[n];
        //making the graph from 2d vector
        for(int i=0;i<pre.size();i++)
            adj[pre[i][1]].push_back(pre[i][0]);
        
        //storing how many incoming node are there
        for(int i=0;i<n;i++){
            for(int it: adj[i])
                indegree[it]++;
        }
        vector<int>ans;
        vector<int>visit(n,0),path(n,0);
        for(int i=0;i<n;i++){
            if(visit[i]==0){
                if(dfscycle(i,visit,path,adj))
                    return ans;
            }
        }
        
        //scan indegree and store the node have indegree 0
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }
      while(!q.empty()){
          int x=q.front();
          ans.push_back(x);
          q.pop();
          for(auto it: adj[x]){
              indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
          }
      }
        return ans;
    }
};