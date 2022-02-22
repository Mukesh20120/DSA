//same as 1 nothing change both question 538 and 1038

class Solution {
public:
    int sum=0;
    TreeNode* convertBST(TreeNode* root) {
         if(root){
             convertBST(root->right);
             root->val+=sum;
             sum=root->val;
             convertBST(root->left);
         }
        return root;
    }
};
