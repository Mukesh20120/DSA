class Solution {
public:
    void dfs(int i,vector<bool>&v,vector<vector<int>>&rooms){
        //marking the visited
        v[i]=true;
        for(int j=0;j<rooms[i].size();j++){
            int x=rooms[i][j];
            if(!v[x])
                dfs(x,v,rooms);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n=rooms.size();
     vector<bool>visited(n,false);  
        
     dfs(0,visited,rooms); 
        
     for(int i=0;i<n;i++){
         if(!visited[i])
             return false;
     }
    return true;
    }
};