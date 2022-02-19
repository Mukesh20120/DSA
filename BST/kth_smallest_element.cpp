/* 1. traverse through the tree and store element in the vector
   2. sort the vector and return the asked kth element
   */
class Solution {
public:
    void preorder(TreeNode *node,vector<int>&ans){
        if(node){
            ans.push_back(node->val);
            preorder(node->left,ans);
            preorder(node->right,ans);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        //vector to store the elements 
        vector<int>ans;
        preorder(root,ans);   
        sort(ans.begin(),ans.end());
        return ans[k-1]; //k-1 due to 1 indexing
    }
};


//2nd method TC O(n) SC o(n)
/* 1. traverse through the tree and store element in the vector
   2. traverse throught inorder so we not need to sort the array
     its inorder property it sorted
   */
class Solution {
public:
    void Inorder(TreeNode *node,vector<int>&ans){
        if(node){
            Inorder(node->left,ans);
            ans.push_back(node->val);
            Inorder(node->right,ans);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        //vector to store the elements 
        vector<int>ans;
        Inorder(root,ans);   
       
        return ans[k-1]; //k-1 due to 1 indexing
    }
};
