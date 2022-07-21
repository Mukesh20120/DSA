class Solution
{
	public:
	
	void dfs(vector<int>&visit,vector<int>adj[],stack<int>&st,int i){
	    visit[i]=1;
	    for(auto it: adj[i]){
	        if(visit[it]==0)
	          dfs(visit,adj,st,it);
	    }
	    st.push(i);
	}
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //topo sort using dfs
	    //nothing new in dfs we just have to do simple
	    //dfs and at the end of each vertices we have to push 
	    //it into the stack 
	    //topo sort is vertices in order ex 5->3->2 then it will 5 3 2
	    vector<int>visit(V,0);//visited array
	    stack<int>st;//stack for storing the vertices
	    vector<int>topo;//in this we store all element of stack
	    for(int i=0;i<V;i++){
	        if(!visit[i]){
	            dfs(visit,adj,st,i);
	        }
	    }
	    while(!st.empty()){
	       topo.push_back(st.top());
	       st.pop();
	    }
	    return topo;
	}
};



//using bfs traversal

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    //bsf
	    //step 1 make  a verter of inverteces of every 
	    //step 2 make a queue treavese through vector and which
	    //have invertices 0  
	    //bsf using q and if verties is 0 push in topo vector
	    vector<int>inorder(V,0);
	    for(int i=0;i<V;i++){
	        for(auto it: adj[i])
	           inorder[it]++;
	    }
	    
	    queue<int>q;
	    
	   for(int i=0;i<V;i++)
	       if(inorder[i]==0)
	           q.push(i);
	    
	    vector<int>topo;
	    while(!q.empty()){
	        int node=q.front();
	        topo.push_back(node);
	        q.pop();
	        for(auto it: adj[node]){
	            inorder[it]--;
	            if(inorder[it]==0)
	              q.push(it);
	        }
	    }     
	   return topo;
	}
};