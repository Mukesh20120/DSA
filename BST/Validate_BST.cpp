/*
 Range property of BST 
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return validate(root,LONG_MIN,LONG_MAX);
    }
    bool validate(TreeNode *node,long minval,long maxval){
        if(node==NULL)
            return true;
        if(node->val <= minval || node->val >= maxval )return false;
        return validate(node->left,minval,node->val) &&
                validate(node->right,node->val,maxval);
    }
};
