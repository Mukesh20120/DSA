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
class Solution {
public:
//finding the maximum value in the array for given range and return the index
    int findmaxi(vector<int>&num,int l,int h){
        int maxi=-1;
        int ind=0;
        for(int i=l;i<=h;i++){
            if(num[i]>maxi){
                maxi=num[i];
                ind=i;
            }
        }
        return ind;
    }
    TreeNode *build(vector<int>&num,int l,int h){
        //base case must be in range
        if(l>h)return NULL;
        
        //index of the max element in the range
        int ind=findmaxi(num,l,h);
        //making the node of max element
        TreeNode*root=new TreeNode(num[ind]);
        //calling for same
        root->left=build(num,l,ind-1);
        root->right=build(num,ind+1,h);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
};