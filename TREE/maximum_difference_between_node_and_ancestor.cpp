
class Solution
{
  public:
    int helper(TreeNode *node, int curmax, int curmin)
    {
        //returning the difference b/w min and max
        if (!node)
        {
            return curmax - curmin;
        }
        //update max value and min value
        curmax = max(node->val, curmax);
        curmin = min(node->val, curmin);
        //passing in left and right tree recursively
        int left = helper(node->left, curmax, curmin);
        int right = helper(node->right, curmax, curmin);
        //taking max difference
        return max(left, right);
    }

    int maxAncestorDiff(TreeNode *root)
    {
        return helper(root, -1, INT_MAX);
    }
};

/**
 nothing much change just declare a global variable to store the difference and 
 each time updating it
 */
class Solution
{
  private:
    int ans;

  public:
    void helper(TreeNode *node, int mx, int mn)
    {
        if (!node)
            return;
        mx = max(mx, node->val);
        mn = min(mn, node->val);
        ans = max(ans, abs(mx - mn));

        helper(node->left, mx, mn);
        helper(node->right, mx, mn);

        return;
    }
    int maxAncestorDiff(TreeNode *root)
    {
        ans = 0;
        int mn = INT_MAX;
        helper(root, -1, mn);
        return ans;
    }
};
