/*
check first root null or not if null then return the new node with val
make two node one store for root address and other one is tail that follow then node
traverse through the tree and when node became null then the tail point on previous of node
check again for where the new node connect left or right
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
     
        TreeNode *node=root;
        if(root==NULL)return new TreeNode(val);
        TreeNode *tail=root;
        while(node){
            tail=node;
            if(node->val > val)
                node=node->left;
            else
                node=node->right;
        }
       
        if(tail->val > val)
            tail->left=new TreeNode(val);
        else
            tail->right=new TreeNode(val);
        
    return root;
    }
};
