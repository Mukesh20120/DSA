//just doing bfs instead of visited array we are using colour vector to check
// colour is different or not visited or not

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //let assume it is the question of colour bipartite

        //total no. of vertices 0 to n-1
        int n=graph.size();

        //it used to store the different colour and used to check visited or not
        vector<int>colour(n,-1);
        //now we do bfs and check color
        //vertice and color 1/0

        //to store the vertices and colour 
        queue<pair<int,bool>>q;

        //traversing  through all the vertices 
        for(int i=0;i<n;i++){
            if(colour[i]!=-1)continue;
        q.push({i,0});
        colour[i]=0;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(int &it: graph[node.first]){
                //assume it not coloured
                if(colour[it]==-1){
                    colour[it]=(!node.second);
                    q.push({it,colour[it]});
                }
                else{
                    if(colour[it]==node.second)
                        return false;
                }
            }
        }
        }
        return true;
    }
};