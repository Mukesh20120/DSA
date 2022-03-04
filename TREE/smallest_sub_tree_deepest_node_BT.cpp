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
//first step to make our own data structure to store and return the value
struct farnode{
    TreeNode *lnode;
    TreeNode *rnode;
};
class Solution {
public:
    farnode deepestnode(TreeNode *root){
        //need to store the ans
        farnode ans;
        if(root==NULL){
            ans.lnode=NULL;
            ans.rnode=NULL;
            return ans;
        }
        //we have check above that the root is not null then we do level order traversal 
        //to find the edge node of the tree
        
        //queue data structure we use it to do level order traversal
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode *node=q.front();
                q.pop();
                //now checking the first and last node of the queue
                if(i==0)ans.lnode=node;
                if(i==n-1)ans.rnode=node;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        return ans;  
    }
    
    TreeNode *LCA(TreeNode *root,farnode f){
        //base case
        if(root==NULL || f.lnode==root || f.rnode==root)
            return root;
        
        //we store the node in left and right
        TreeNode *left=LCA(root->left,f);
        TreeNode *right=LCA(root->right,f);
        
        //check condition while returning tail recursion
        if(left==NULL)return right;
        if(right==NULL)return left;
        
        return root;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        //question break down into two parts in first part we need to find the 
        //node of edge of the binary tree or say that farnode
        
        //the variable take left and right edge node and the function reuturn the value
        farnode f= deepestnode(root);
        
        //now we have to find the path of both node of left and right we get 
        //question break down to find the path of the given two node
        //first method is to store the path of both node one by one in two vectore 
        //traverse through vector if found different then it is our LCA
        TreeNode *ans=LCA(root,f);
        return ans;
    }
};