class Solution {
  public:
    vector <int> bottomView(Node *root) {
        //answer vector
        vector<int>ans;
        //map for store the element
        map<int,int>map;
        queue<pair<int,Node*>>q;
        q.push({0,root});
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int x=q.front().first;
                Node *temp=q.front().second;
                q.pop();
                map[x]=temp->data;
                if(temp->left)
                 q.push({x-1,temp->left});
                 if(temp->right)
                 q.push({x+1,temp->right});
            }
        }
        for(auto &it: map){
            ans.push_back(it.second);
        }
        return ans;
    }
};