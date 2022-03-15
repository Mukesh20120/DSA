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
    vector<TreeNode *>generate(int n){
       if(n==1){
           return {new TreeNode(0)};
       }
       vector<TreeNode *>tree,left,right;
        n--;
        for(int i=1;i<n;i+=2){
            left=generate(i);
            right=generate(n-i);
            for(auto l: left){
                for(auto r: right){
                    TreeNode *temp=new TreeNode(0);
                    temp->left=l;
                    temp->right=r;
                    tree.push_back(temp);
                }
            }
        }
        return tree;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*>ans;
        if(n==1){
         return {new TreeNode(0)};
        }
        else if(n%2==0)
            return ans;
       ans=generate(n);
        return ans;
    }
};