/*
 break down question into two part in firs we are finding the lowest common leaves of the
 tree 
 2. we are find the lowest common ancestor of the above finded nodes
 */
//to store the left and right node of the tree
struct farnode{
    TreeNode *lnode;
    TreeNode *rnode;
};
class Solution {
public:
//finding the lowest leaf node left and right and returning it
    farnode deepestnode(TreeNode* root){
        //finding the deepest node 
        farnode ans; //return answer
        //check for root is present or not
        if(!root){
            ans.lnode=NULL;
            ans.rnode=NULL;
        }
        //level order traversal 
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode *node=q.front();
                q.pop();
                //store the first and the last node of the end 
                if(i==0)ans.lnode=node;
                if(i==n-1)ans.rnode=node;
                //simple level order traversal
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return ans;
    }

    //question break down to find the lca of two given node lca
    TreeNode *lca(TreeNode *root,TreeNode *p,TreeNode *q){
        if(!root || root==p || root==q)
            return root;
        TreeNode *left=lca(root->left,p,q);
        TreeNode *right=lca(root->right,p,q);
        if(!left)return right;
        if(!right)return left;
    
            return root;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        //it give the deepest node of the tree which have left and rigth node
        farnode far1=deepestnode(root);
     
        //now we have to find the path or lowest common ancestore
        TreeNode *ans=lca(root,far1.lnode,far1.rnode);
        
        return ans;
    }
};