class Solution {
public:
    bool dfsRec(int i,vector<bool>&visit,vector<bool>&path,vector<vector<int>>&adj,vector<bool>&inloop){
    //marking the visit and path that we covered it
        visit[i]=true;
        path[i]=true;
        //traverse through all the connected node of adj[i]
        vector<int>data=adj[i];
        for(auto it: data){
            if(!visit[it]){
                if(dfsRec(it,visit,path,adj,inloop))
                     return inloop[i]=true;
            }
            else if(path[it] && visit[it])
                return inloop[i]=true;
        }
        //backtracking marked the path again
        path[i]=false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //firs we have to check the cycle present or not in the graph 
        //make adj list for graph
        
        //total number of nodes in graph
        int n=graph.size();
        //question boil down to check the cycle in graph
        //two vector one for visited mark and one for path check
        vector<bool>visit(n,false),path(n,false);
        
        //present in loop or not marking in vector
        vector<bool>inloop(n,false);
        
        //traverse through each node
        for(int i=0;i<n;i++){
            if(!visit[i]){
                dfsRec(i,visit,path,graph,inloop);
            }
        }
        //now our inloop vector store all the node that are came in loop and the
        //remain element are our answers
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!inloop[i])
                ans.push_back(i);
        }
        return ans;
    }
};