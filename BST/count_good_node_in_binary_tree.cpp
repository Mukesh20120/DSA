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
    int goodNodes(TreeNode* root) {
        int ans=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,INT_MIN});
        while(!q.empty()){
            TreeNode *t=q.front().first;
            int maxi=q.front().second;
            q.pop();
            if(t->val>=maxi){
                ans++;
                maxi=t->val;
            }
            if(t->left)
                q.push({t->left,maxi});
            if(t->right)
                q.push({t->right,maxi});
        }
        return ans;
    }
};


/////////////////////recursion////////////////////////////
class Solution {
public:
    int solve(TreeNode* root,int maxi){
        if(root==NULL)
            return 0;
        maxi=max(maxi,root->val);
        if(root->val>=maxi)
            return 1+solve(root->left,maxi)+solve(root->right,maxi);
        return solve(root->left,maxi)+solve(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        return solve(root,INT_MIN);
    }
};