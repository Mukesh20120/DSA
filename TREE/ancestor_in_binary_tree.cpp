//taking reference from root to leaf path same pattern

class Solution{
    private:
    vector<int>ans;
  public:
  void helper(struct Node *root,vector<int>temp,int t){
      if(root==NULL)return;
      if(root->data==t){
          ans=temp;
          return;
      }
      temp.push_back(root->data);
      helper(root->left,temp,t);
      helper(root->right,temp,t);
  }
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target)
    {
        vector<int>temp;
        helper(root,temp,target);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};