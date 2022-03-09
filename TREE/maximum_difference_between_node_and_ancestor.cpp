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
    int helper(TreeNode *node,int curmax,int curmin){
        //returning the difference b/w min and max
        if(!node){
            return curmax-curmin;
        }
        //update max value and min value
        curmax=max(node->val,curmax);
        curmin=min(node->val,curmin);
        //passing in left and right tree recursively
        int left=helper(node->left,curmax,curmin);
        int right=helper(node->right,curmax,curmin);
        //taking max difference
        return max(left,right);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        return helper(root,-1,INT_MAX);
    }
};



