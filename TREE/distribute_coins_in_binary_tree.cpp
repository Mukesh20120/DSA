/*
DFS solution

 */
class Solution {
    private: 
    int step=0;
public:
    int helper(TreeNode *root){
        if(root==NULL)
            return 0;
        int l=helper(root->left);
        int r=helper(root->right);
        step+=abs(l)+abs(r);
        return (l+r+root->val-1);
    }
    int distributeCoins(TreeNode* root) {
        helper(root);
        return step;
    }
};