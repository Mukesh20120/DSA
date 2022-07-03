void helper(struct Node *root,vector<int>&ans,int k){
  if(root==NULL)return;
  if(k==0){
      ans.push_back(root->data);
      return;
  }
  helper(root->left,ans,k-1);
  helper(root->right,ans,k-1);
}
vector<int> Kdistance(struct Node *root, int k)
{
  vector<int>ans;
  helper(root,ans,k);
  return ans;
}