
class Solution {
public:
    void markingpar(TreeNode *root,unordered_map<TreeNode*,TreeNode*>&hash){
        //we will do level ordere traversal using queue
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
                TreeNode *cur=q.front();
                q.pop();
                if(cur->left){
                    q.push(cur->left);
                    hash[cur->left]=cur;
                }
                if(cur->right){
                    q.push(cur->right);
                    hash[cur->right]=cur;
                }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //make unorder map to store the parents 
        unordered_map<TreeNode*,TreeNode*>hash;
        //filling the unordered map with its parents
        markingpar(root,hash);
        
        //now we need to traverse in 3 direction top,left and right
        queue<TreeNode*>q;
        q.push(target);
        //making unordered map for marking visited or not
        unordered_map<TreeNode*,bool>visit;
        visit[target]=true;
        int level=0;
        while(!q.empty()){
            int sz=q.size();
            if(level==k)break;
            for(int i=0;i<sz;i++){
                TreeNode* cur=q.front();
                q.pop();
              
                if(cur->left && !visit[cur->left]){
                    q.push(cur->left);
                    visit[cur->left]=true;
                }
                if(cur->right && !visit[cur->right]){
                    q.push(cur->right);
                    visit[cur->right]=true;
                }
                if(hash[cur] && !visit[hash[cur]]){
                    q.push(hash[cur]);
                    visit[hash[cur]]=true;
                }
            }
            level++;
        }
        vector<int>res;
        while(!q.empty()){
          TreeNode *c=q.front();
            res.push_back(c->val);
            q.pop();
        }
        return res;
    }
};