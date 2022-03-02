class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        //base case
        if(root==NULL)return 0;
        //here are two case 1 is when parents are even and other when it is odd 
        if(root->val%2==0){ //if even we are adding all the grand child of the possible tree node
        int sum=0;
        if(root->left && root->left->left)
            sum+=root->left->left->val;
        if(root->left && root->left->right)
            sum+=root->left->right->val;
        if(root->right && root->right->left)
            sum+=root->right->left->val;
        if(root->right && root->right->right)
            sum+=root->right->right->val;
            //here returning the value that sum up and left side and right side
        return sum+sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
        }
        else//when the root->val is odd then we don't need to calculate the sum of child
            return sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
    }
};