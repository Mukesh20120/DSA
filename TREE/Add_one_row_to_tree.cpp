/* 
doing by traversal
store in queue above row and make row and changing pointer
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        //when depth is 1 we have to change root
        if(depth==1){
          TreeNode *temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        //simply level order traversal
        int level=1;
        queue<TreeNode*>q; 
        q.push(root);
        //storing the last depth node below which new nodes added
        while(level!=depth-1){
            int n=q.size();
            level++;
            for(int i=0;i<n;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        //adding the new row and replacing the pointer
        while(!q.empty()){
            TreeNode *t=q.front();
            q.pop();
            TreeNode *l=new TreeNode(val);
            TreeNode *r=new TreeNode(val);
            l->left=t->left;
            r->right=t->right;
            t->left=l;
            t->right=r;
        }
        return root;
    }
};

//2 method recursivly
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        Insert(val,root,depth,1);
        return root;
    }
    void Insert(int v,TreeNode *node,int d,int n){
        if(!node)return;
        if(d==n-1){
            TreeNode *l=new TreeNode(v);
            TreeNode *r=new TreeNode(v);
            l->left=node->left;
            r->right=node->right;
            node->left=l;
            node->right=r;
            return;
        }
        else{
            Insert(v,node->left,d,n+1);
            Insert(v,node->right,d,n+1);
        }
    }
};