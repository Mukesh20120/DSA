/*
first method naive apporach in this method we 
traverse through tree preorder left right root
and while return we check if the node is leaf or not
if the node is leaf node then check if the root value is the same as given target value
return according to it
*/

class Solution {
public:
   
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root)return NULL;
        //same as preorder traversal
        root->left=removeLeafNodes(root->left,target);
        root->right=removeLeafNodes(root->right,target);
        //check if the leaf node or not
        if(!root->left && !root->right)
            return root->val==target?NULL:root; //again condition if target equal to the root value
            //then reutrn null to make all the down from leaf node to null if not then return root
        
        return root;
    }
};