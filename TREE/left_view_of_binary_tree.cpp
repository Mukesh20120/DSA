//using iterator and map to store the level and the root value

 vector<int> leftView(Node *root)
{
   vector<int>ans;
   if(root==NULL)
   return ans;
   map<int,int>hash;
   queue<pair<int,Node*>>q;
   q.push({0,root});
   while(!q.empty()){
       auto p=q.front();
       q.pop();
       Node *t=p.second;
       int l=p.first;
       if(hash.find(l)==hash.end())
         hash[l]=t->data;
       if(t->left)
         q.push({l+1,t->left});
       if(t->right)
         q.push({l+1,t->right});
   }
   for(auto &it: hash)
     ans.push_back(it.second);
     
     return ans;
}


//recursion approach using stack

void helper(Node *root,int level,vector<int>&ans){
    if(root){
        if(level==ans.size())
             ans.push_back(root->data);
        helper(root->left,level+1,ans);
        helper(root->right,level+1,ans);
    }
    }                           
            
        
vector<int> leftView(Node *root)
{
   //vector for returning the answer
   vector<int>ans;
   //passing in the function
   //node level and ans vector
   helper(root,0,ans);
   return ans;
}


//optimal solution using only queue for level order traversal
//code working in leetcode only
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
    vector<int> rightSideView(TreeNode* root) {
        
   vector<int>ans;
        if(root==NULL)
            return ans;
   queue<pair<int,TreeNode*>>q;
   q.push({0,root});
   while(!q.empty()){
       auto p=q.front();
       q.pop();
       TreeNode *node=p.second;
       int l=p.first;
       if(l==ans.size())
          ans.push_back(node->val);
       if(node->right)
         q.push({l+1,node->right});
       if(node->left)
          q.push({l+1,node->left});
   }
   return ans;
    }
};