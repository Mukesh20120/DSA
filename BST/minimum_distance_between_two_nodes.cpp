//530 minimum absolute diffence b/w nodes same question 783 minimum distance b/w two nodes
class Solution
{
  private:
    int mini = INT_MAX;
    int val = -1;

  public:
    int minDiffInBST(TreeNode *root)
    {
        if (root->left)
            minDiffInBST(root->left);
        if (val >= 0)
            mini = min(mini, root->val - val);
        val = root->val;
        if (root->right)
            minDiffInBST(root->right);
        return mini;
    }
};