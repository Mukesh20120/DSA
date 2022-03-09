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
class Solution
{
  public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        fun(ans, root, "");
        return ans;
    }
    void fun(vector<string> &ans, TreeNode *root, string s)
    {
        if (!root)
            return;
        string a = to_string(root->val);
        string s1;
        if (!s.length())
            s1 = a;
        else
            s1 = s + "->" + a;

        if (!root->left && !root->right)
        {
            ans.push_back(s1);
            return;
        }

        fun(ans, root->left, s1);
        fun(ans, root->right, s1);
    }
};

//previous code little bit improve in syntax
class Solution
{
  public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        fun(ans, root, "");
        return ans;
    }
    void fun(vector<string> &ans, TreeNode *root, string s)
    {
        s = s.empty() ? s + to_string(root->val) : s + "->" + to_string(root->val);
        if (!root->left && !root->right)
        {
            ans.push_back(s);
            return;
        }

        if (root->left)
            fun(ans, root->left, s);
        if (root->right)
            fun(ans, root->right, s);
    }
};