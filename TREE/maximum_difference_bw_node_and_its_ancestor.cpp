void helper(Node *node,int cur,int &ans){
    if(node==NULL)return;
    ans=max(ans,cur-node->data);
    cur=max(cur,node->data);
    helper(node->left,cur,ans);
    helper(node->right,cur,ans);
}

int maxDiff(Node* root)
{
  int ans=INT_MIN;
  helper(root,ans+root->data,ans);
  return ans;
}