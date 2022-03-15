/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode *root){
        //checking if it is not a leaf node then returning the maximum value
        //so it will discarded when return 
        if(root==NULL)return 1e5;
        
        //checking the leaf node
        if(!root->left && !root->right)return 1;
        
        //size of left sub tree
        int a=height(root->left);
        //size of right sub tree
        int b=height(root->right);
        
        return a>b?b+1:a+1;
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int mn=height(root);
        return mn;
    }
};