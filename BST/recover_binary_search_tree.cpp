/*
storing in vector taking extra space
*/

class Solution {
public:
    void Inorder(TreeNode *node,vector<TreeNode*>&val){
        if(!node)return;
        Inorder(node->left,val);
        val.push_back(node);
        Inorder(node->right,val);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*>val;
        Inorder(root,val);
        TreeNode *first=NULL,*second,*last=NULL;
        for(int i=0;i<val.size()-1;i++){
            if(val[i]>val[i+1] && !first){
                first=val[i];
                second=val[i+1];
            }
            else
                last=val[i];
        }
        if(!first)
            swap(first,second);
        else
            swap(first,last);
    }
};

/*
optimal solution just traversal through the tree inorder
*/
class Solution {
    private:
    TreeNode *first=NULL,*middle=NULL,*last=NULL,*prev=NULL;
public:
    void Inorder(TreeNode *node){
        if(node==NULL)return;
        Inorder(node->left);
        if(prev && prev->val > node->val){
            if(!first){
                first=prev;
                middle=node;
            }
            else
                last=node;
        }
        prev=node;
        Inorder(node->right);
    }
    void recoverTree(TreeNode* root) {
        Inorder(root);
        if(first && last)
            swap(first->val,last->val);
        else
            swap(first->val,middle->val);
    }
};

