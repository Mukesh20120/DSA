//based on height of bst and diameter of bst

class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    
    int helper(Node *root,int &sum){
        if(!root)return 0;
        int lh=max(0,helper(root->left,sum));
        int rh=max(0,helper(root->right,sum));
        sum=max(sum,lh+rh+root->data);
        return  root->data+max(lh,rh);
    }
    
    int findMaxSum(Node* root)
    {
        //question is similar with
        //height,diameter
        if(root==NULL)return 0;
        int maxsum=INT_MIN;
        helper(root,maxsum);
        return maxsum;
    }
};
