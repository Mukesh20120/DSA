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
class FindElements {
    private:
      unordered_set<int>hash;
public:
    void helper(TreeNode *root){
        if(root==NULL)
            return;
        if(root->left){
             root->left->val=root->val*2+1;
             hash.insert(root->val*2+1);
        }    
        if(root->right){
             root->right->val=root->val*2+2;
             hash.insert(root->val*2+2);
        }
           
        helper(root->left);
        helper(root->right);
    }
    FindElements(TreeNode* root) {
        root->val=0;
        hash.insert(0);
        helper(root);
    }
    
    bool find(int t) {
        if(hash.find(t)==hash.end())
            return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */