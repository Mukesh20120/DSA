/*
as it is bst then it property slightly change in inorder all element in decending order
and we easily add and replace it 

the code also work if we take the sum as global variable 
*/

class Solution {
public:
   
    void construct(TreeNode *node,int &sum){
        if(node){
            construct(node->right,sum);
            node->val+=sum;
            sum=node->val;
            construct(node->left,sum);
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
      construct(root,sum);
        return root;
    }
};
