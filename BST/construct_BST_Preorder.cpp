/* same as make a tail pointer and traverse throught the 
   tree when find end position insert it there
*/

class Solution {
public:
    void Insert(TreeNode *node,int key){
      TreeNode *tail=node;
        while(node){
            tail=node;
            if(node->val > key)
                node=node->left;
            else
                node=node->right;
        }
        if(tail->val > key)
            tail->left=new TreeNode(key);
        else
            tail->right=new TreeNode(key);
            
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode *root=new TreeNode(pre[0]);
        for(int i=1;i<pre.size();i++)
            Insert(root,pre[i]);
        return root;
    }
};
