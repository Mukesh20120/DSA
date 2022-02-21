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


//2nd method TC O(N) SC(1) auxilary space
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int i=0;
        return construct(pre,i,INT_MAX);
    }
    TreeNode *construct(vector<int>&pre,int &i,int ub){
        //base case
        if(i==pre.size() || pre[i]>ub)return NULL;
        //what to do
        TreeNode *root=new TreeNode(pre[i++]);
        //all choice
        root->left=construct(pre,i,root->val);
        root->right=construct(pre,i,ub);
        return root;
    }
};

