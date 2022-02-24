/*
1.method naive approach 
store the all the treeNode in the vectore in inorder 
now rearrange the order order and make the last node right and left as null
TC o(n) SC o(n)
*/

class Solution {
public:
    void Inorder(TreeNode *node,vector<TreeNode*>&val){
        if(node==NULL)return;
        Inorder(node->left,val);
        val.push_back(node);
        Inorder(node->right,val);
    }
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL)return NULL;
        vector<TreeNode*>val;
        Inorder(root,val);
        TreeNode *temp=val[0];
        int i;
        for(i=1;i<val.size();i++){
            temp->left=NULL;
            temp->right=val[i];
            temp=temp->right;
        }
        temp->left=temp->right=NULL;
        return val[0];
    }
};
