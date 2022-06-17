//using unordered set to check it present or not
class Solution {
    private:
      int cam;
      unordered_set<TreeNode*>covered;
public:
    void dfs(TreeNode *root,TreeNode *parents){
        if(root!=NULL){
            //we go deep in the tree
            dfs(root->left,root);
            dfs(root->right,root);
            //we have two condition to check
            //if parents is null and it not covered by any camera
            //or if left or right child not covered by camera then add camera
            if((parents==NULL && covered.find(root)==covered.end()) 
                || covered.find(root->left)==covered.end()
                || covered.find(root->right)==covered.end()){
                cam++;
                //now add all parents child
                covered.insert(parents);
                covered.insert(root);
                covered.insert(root->left);
                covered.insert(root->right);
            }
        }
    }

//optimal solution using variable
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
    private:
     int cam;
public:
    //1-->covered by camera
    //2-->have camera
    //0-->not covered by camera
    int dfs(TreeNode *node){
        //base case
        if(node==NULL)return 1;
        //go to the end of the tree
        int l=dfs(node->left);
        int r=dfs(node->right);
        
        if(l==0 || r==0){
            cam++;
            return 2;
        }
        else if(l==2 || r==2)
            return 1;
        else
            return 0;
    }
    int minCameraCover(TreeNode* root) {
       cam=0;
      return dfs(root)==0?cam+1:cam;
    }
};
    
    int minCameraCover(TreeNode* root) {
        cam=0;
       
        //we need to add the NULL because for the childeren at the end
        covered.insert(NULL);
         //passing in the function
        //root and its parents
        dfs(root,NULL);
        return cam;
    }
};