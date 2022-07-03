class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        map<int,int>map;
        queue<pair<int,Node*>>q;
        q.push({0,root});
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int x=q.front().first;
                Node *temp=q.front().second;
                q.pop();
                if(map.find(x)==map.end())
                   map[x]=temp->data;
                if(temp->left)
                  q.push({x-1,temp->left});
                if(temp->right)
                q.push({x+1,temp->right});
            }
        }
        for(auto &it: map)
          ans.push_back(it.second);
          
    return ans;
    }

};
