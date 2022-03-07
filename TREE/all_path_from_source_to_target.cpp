class Solution {
public:
    void dfs(vector<vector<int>>&graph,vector<int>&level,vector<vector<int>>&ans,int tar,int cur){
        level.push_back(cur);
        if(cur==tar)ans.push_back(level);
        
        for(int it: graph[cur])
            dfs(graph,level,ans,tar,it);
        level.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>level;
        int target=graph.size()-1;
        dfs(graph,level,ans,target,0);
        return ans;
    }
};