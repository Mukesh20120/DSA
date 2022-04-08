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
    int horob(TreeNode * root){
        if(root==NULL)return 0;
        //now we have two option first we take root and grand  child and move on
        int val=0;
        if(root->left!=NULL){
            val+=horob(root->left->left);
           val+=horob(root->left->right);

          }
        if(root->right!=NULL){
             val+=horob(root->right->left);
           val+=horob(root->right->right);
        }
        return max(root->val+val,horob(root->left)+horob(root->right));
    }
    int rob(TreeNode* root) {
        return horob(root);
    }
};

//memoization using unordered map
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
    private:
      unordered_map<TreeNode*, int>mp;
public:
    int horob(TreeNode * root){
        if(root==NULL)return 0;
        //now we have two option first we take root and grand  child and move on
        int val=0;
        if(mp.find(root)!=mp.end())
            return mp[root];
        if(root->left!=NULL){
            val+=horob(root->left->left);
           val+=horob(root->left->right);

          }
        if(root->right!=NULL){
             val+=horob(root->right->left);
           val+=horob(root->right->right);
        }
        return mp[root]=max(root->val+val,horob(root->left)+horob(root->right));
    }
    int rob(TreeNode* root) {
        return horob(root);
    }
};