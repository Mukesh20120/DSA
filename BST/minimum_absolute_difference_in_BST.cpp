/*
Naive approach
1 make a vector
2 store the value in inorder 
3 and as we know the minimum difference is the two adjecent value traver using loop
finding differnce b/w two adjecent values
*/
class Solution
{
  public:
    void Inorder(TreeNode *root, vector<int> &val)
    {
        if (root)
        {
            Inorder(root->left, val);
            val.push_back(root->val);
            Inorder(root->right, val);
        }
    }
    int getMinimumDifference(TreeNode *root)
    {
        vector<int> val;
        Inorder(root, val);
        int diff = 0;
        int mini = INT_MAX;
        for (int i = 0; i < val.size() - 1; i++)
        {
            diff = abs(val[i] - val[i + 1]);
            mini = min(mini, diff);
        }
        return mini;
    }
};
//2 method optimal method without using extra space
class Solution
{
  public:
    //here we need to change val and mini in every call so it taken by reference
    //we can also use global variable also
    void Inorder(TreeNode *root, int &val, int &mini)
    {
        if (root->left)
            Inorder(root->left, val, mini);
        //this condition used once to get previous value as last value
        if (val >= 0)
            mini = min(mini, root->val - val);
        val = root->val;
        if (root->right)
            Inorder(root->right, val, mini);
    }
    int getMinimumDifference(TreeNode *root)
    {
        int mini = INT_MAX;
        int val = -1;
        Inorder(root, val, mini);
        return mini;
    }
};