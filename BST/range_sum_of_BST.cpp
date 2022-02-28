/*
naive approach int this method we made a global variable and add the value when it is in range by simple traversal
*/
class Solution
{
  private:
    int sum = 0;

  public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        //base case
        if (root == NULL)
            return 0;

        if (root->val >= low && root->val <= high)
            sum += root->val;
        rangeSumBST(root->left, low, high);
        rangeSumBST(root->right, low, high);

        return sum;
    }
};

//second method using extra space to store the value in sorted order or any order
//you want and use for loop to traverse through it
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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        vector<int> val;
        Inorder(root, val);
        int sum = 0;
        for (int &it : val)
        {
            if (it >= low && it <= high)
                sum += it;
        }
        return sum;
    }
};
//just doing inorder traversal and make a variable to store the value that fall in the range
class Solution
{

  public:
    void Inorder(TreeNode *root, int l, int h, int &sum)
    {
        if (root)
        {
            Inorder(root->left, l, h, sum);
            if (root->val >= l && root->val <= h)
                sum += root->val;
            Inorder(root->right, l, h, sum);
        }
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int sum = 0;
        Inorder(root, low, high, sum);
        return sum;
    }
};