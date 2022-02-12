/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent_child(unordered_map<TreeNode*,TreeNode*>&mp,TreeNode* root){
        //queue data structure for store bfs traversal
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
         auto p=q.front();
            q.pop();
            if(p->left){
                mp[p->left]=p;
                q.push(p->left);
            }
            if(p->right){
                mp[p->right]=p;
                 q.push(p->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //making a parent and child relation map
        unordered_map<TreeNode *,TreeNode *>mp;
        //filling the map
        parent_child(mp,root);
        //making another map to check for visited
        unordered_map<TreeNode *,bool>visit;
        queue<TreeNode*>q;
        q.push(target);
        visit[target]=true;
        int count=0;
        while(!q.empty()){
            int sz=q.size();
            if(count++==k)break;
            for(int i=0;i<sz;i++){
                auto p=q.front();
                q.pop();
                if(p->left && !visit[p->left]){
                    q.push(p->left);
                    visit[p->left]=true;
                }
                if(p->right && !visit[p->right]){
                    q.push(p->right);
                    visit[p->right]=true;
                }
                if(mp[p] && !visit[mp[p]]){
                    q.push(mp[p]);
                    visit[mp[p]]=true;
                }
            }
        }
        //the while loop break when count=k
        vector<int>result;
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            result.push_back(node->val);
        }
        return result;
    }
};
