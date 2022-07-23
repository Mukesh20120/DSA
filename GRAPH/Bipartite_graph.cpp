class Solution {
public:
   bool bfsbipartite(vector<int>adj[],int node,vector<int>&color){
       queue<int>q; 
       q.push(node); //pushing first node in queue
       color[node]=1; //marking as color and also visited
       while(!q.empty()){ //bfs traversal
           int x=q.front();
           q.pop();
           //traversal all its connected node
           for(auto &it: adj[x]){
               //we have two case if color is -1 other
               //we have check adjacent node color
               if(color[it]==-1){ //checking visited also
                   color[it]=1-color[x]; //marking different color
                   q.push(it); //push it in queue
               }
               else if(color[it]==color[x])//other case if it already color check if it is same or not
                 return false;
           }
       }
       return true;
   }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int>color(V,-1);//it work as both visited as well as for color also
	   // if we are given differnt graph of node
	    for(int i=0;i<V;i++){
	       if(color[i]==-1)//check as visited
	        if(!bfsbipartite(adj,i,color))//starting the graph
	          return false;
	    }
	    return true;
	}

};


//dfs 

class Solution {
public:
bool dfs(vector<int>adj[],vector<int>&color,int i){
    if(color[i]==-1)color[i]=1;
    for(auto it: adj[i]){
        if(color[it]==-1){
            color[it]=!color[i];
            if(!dfs(adj,color,it))
                return false;
        }else if(color[it]==color[i])
           return false;
    }
    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	   vector<int>color(V,-1);
	   for(int i=0;i<V;i++){
	       if(color[i]==-1)
	          if(!dfs(adj,color,i))
	            return false;
	   }
	   return true;
	}
};