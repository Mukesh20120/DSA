class Solution {
  public:
  int height(Node *root,int &maxi){
      if(root==NULL)return 0;
      int lh=height(root->left,maxi);
      int rh=height(root->right,maxi);
      maxi=max(maxi,lh+rh);
      return 1+max(lh,rh);
  }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root==NULL)return 0;
       int maxi=0;
       height(root,maxi);
       return maxi+1;
    }
};
