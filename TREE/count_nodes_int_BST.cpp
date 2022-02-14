class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int lh=findheightleft(root);
        int rh=findheightright(root);
        
        if(lh==rh)return (1<<lh)-1;
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int findheightleft(TreeNode *root){
        int h=0;
        while(root){
            h++;
            root=root->left;
        }
        return h;
        
    }
    int findheightright(TreeNode *root){
        int h=0;
        while(root){
            h++;
            root=root->right;
        }
        return h;
        
    }
};

