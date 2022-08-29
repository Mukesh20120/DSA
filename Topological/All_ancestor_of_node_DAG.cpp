class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        //topology sort
    
        //make adjacent list as it is DAG just one edge from parent to node
        vector<int>adj[n];
        for(auto &it: edges)
            adj[it[0]].push_back(it[1]);
        //inorder array
        vector<int>indeg(n);
        for(int i=0;i<n;i++)
            for(int &it: adj[i])
                indeg[it]++;
        
        //now we take a queue and push all the node have 0 indegree
        queue<int>q;
        for(int i=0;i<n;i++)
            if(indeg[i]==0)
                 q.push(i);
        
        vector<set<int>>ans(n);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &it: adj[node]){
               // append(ans,node,it);
                
                for(auto a=ans[node].begin();a!=ans[node].end();a++)
                   ans[it].insert(*a);
                
                ans[it].insert(node);
                
                
                if(--indeg[it]==0){
                    q.push(it);
                }
            }
        }
        vector<vector<int>>res(n);
       for(int i=0;i<n;i++)
           for(auto a=ans[i].begin();a!=ans[i].end();a++)
               res[i].push_back(*a);
       
        
       return res;
    }
  
};