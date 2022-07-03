class Solution {
public:
    int helper(Node *root,int &res){
        if(root==NULL)return 0;
        if(!root->left && !root->right)return root->data;
        int l=helper(root->left,res);
        int r=helper(root->right,res);
       
       if(root->left && root->right){
           res=max(res,l+r+root->data);
           
           return max(l,r)+root->data;
       }
       return (!root->left)?root->data+r:root->data+l;
    }
    int maxPathSum(Node* root)
    {
      int res=INT_MIN;
     
     int val=helper(root,res);
     if(!root->left || !root->right)
       return max(val,res);
      return res;
    }
};