class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //answer vector
        vector<int>ans;
        if(n==0)return ans;
        if(n==1){
             ans.push_back(0);
            return ans;
        }
        //making adjacency list and a vector for collection of degree of each node
        vector<int>degree(n,0);
        vector<int>adj[n];
        //filling the degree and adj list
        for(int i=0;i<edges.size();i++){
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        //making queue data structure push all the node with degree 1
        queue<int>q;
        for(int i=0;i<n;i++){
            if(degree[i]==1)
                q.push(i);
        }
        
        while(n>2){
            int sz=q.size();
            n-=sz;
            while(sz--){
                int x=q.front();
                q.pop();
                for(auto &it: adj[x]){
                    degree[it]--;
                    if(degree[it]==1)
                        q.push(it);
                }
            }
        }
        //now push every element of queue in ans
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};