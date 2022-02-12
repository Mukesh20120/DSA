
class Solution {
  public:
    Node* fill_find(Node *root,map<Node *,Node *>&mp,int x){
        //queue data structure for bfs traversal
        queue<Node*>q;
        q.push(root);
        Node *res=NULL;
        while(!q.empty()){
            Node *p=q.front();
            q.pop();
            if(p->data==x)res=p;
            if(p->left){
                mp[p->left]=p;
                q.push(p->left);
            }
            if(p->right){
                mp[p->right]=p;
                q.push(p->right);
            }
        }
        return res;
    }
    int finding(map<Node *,Node *>&mp,Node *tar){
        //making another map to check visited of not
        //queue for bfs traversal
        map<Node *,int>visit;
        queue<Node *>q;
        int ans=0;
        q.push(tar);
        visit[tar]=1;
        while(!q.empty()){
            int fl=0;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                //left and visited or not
                auto node= q.front();
                q.pop();
                if(node->left && !visit[node->left]){
                    fl=1;
                    visit[node->left]=1;
                    q.push(node->left);
                }
                if(node->right && !visit[node->right]){
                    fl=1;
                    visit[node->right]=1;
                    q.push(node->right);
                }
                if(mp[node] && !visit[mp[node]]){
                    fl=1;
                    visit[mp[node]]=1;
                    q.push(mp[node]);
                }
            }
           if(fl)ans++; 
        }
        return ans;
    }
    
    
    int minTime(Node* root, int target) 
    {
       //make a map for storing the parent of each by BFS traversal
         //child,parents
       map<Node *,Node *>mp;
       //filling the map from node and its parents and finding the target node
       Node *tar=fill_find(root,mp,target);
       int mt=finding(mp,tar);
       return mt;
    }
};