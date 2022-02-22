/*
 1. store the value of tree in array in sorted order - inorder traversal
 2. construct a balance tree from the sorted given array question same as it is
 3. same pattern question of construct bst form linked list
*/

class Solution {
public:
    void Inorder(TreeNode *node,vector<int>&val){
        if(node){
            Inorder(node->left,val);
            val.push_back(node->val);
            Inorder(node->right,val);
        }
    }
    TreeNode* construct(vector<int>&val,int l,int h){
        if(l<=h){
            int mid=l+(h-l)/2;
            TreeNode *root=new TreeNode(val[mid]);
            root->left=construct(val,l,mid-1);
            root->right=construct(val,mid+1,h);
            
          return root;
        }
        return NULL;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>val;
        Inorder(root,val);
        return construct(val,0,val.size()-1);
    }
};

// little bit optimization of above code 
class Solution {
public:
    void Inorder(TreeNode *node,vector<TreeNode*>&val){
        if(node){
            Inorder(node->left,val);
            val.push_back(node);
            Inorder(node->right,val);
        }
    }
    TreeNode* construct(vector<TreeNode*>&val,int l,int h){
        if(l>h)
          return NULL;
        
            int mid=l+(h-l)/2;
            TreeNode *root=val[mid];
            root->left=construct(val,l,mid-1);
            root->right=construct(val,mid+1,h);
          return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>val;
        Inorder(root,val);
        return construct(val,0,val.size()-1);
    }
};
