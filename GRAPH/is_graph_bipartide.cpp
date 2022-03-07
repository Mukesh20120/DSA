class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //let assume it is the question of colour bipartite
        int n=graph.size();
        vector<int>colour(n,-1);
        //now we do bfs and check color
        //vertice and color 1/0
        queue<pair<int,bool>>q;
        for(int i=0;i<n;i++){
            if(colour[i]!=-1)continue;
        q.push({i,0});
        colour[i]=0;
        //simple bfs traversel
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            //pushing all the connected node of the current node
            for(int &it: graph[node.first]){
                //assume it not coloured
                if(colour[it]==-1){
                    colour[it]=(!node.second);
                    q.push({it,colour[it]});
                }
                else{ //if it is already colour then check it is ok or not
                    if(colour[it]==node.second)
                        return false;
                }
            }
        }
        }
        return true;
    }
};