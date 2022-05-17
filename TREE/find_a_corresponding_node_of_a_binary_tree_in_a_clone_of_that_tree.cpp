/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    private:
    TreeNode *ans;
public:
    void helper(TreeNode *cloned,TreeNode *target){
        if(cloned==NULL)
            return;
        if(target->val==cloned->val){
            ans=cloned;
            return;
        }
       
      helper(cloned->left,target);
     helper(cloned->right,target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        //let solve this using recursion
        helper(cloned,target);
        return  ans;
    }
};



//above code using queue and iteration
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*>q;
        q.push(cloned);
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            if(node->val==target->val)
                return node;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return NULL;
    }
};