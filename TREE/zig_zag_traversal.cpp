//gfg return in 1d vector
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        //answer vector
        vector<int>ans;
        queue<Node *>q;
        q.push(root);
        bool lefttoright=true;
        while(!q.empty()){
            int sz=q.size();
            vector<int>temp(sz);
          //running a loop
          for(int i=0;i<sz;i++){
              Node *t=q.front();
              q.pop();
              int index=lefttoright?i:sz-1-i;
              temp[index]=t->data;
              if(t->left)
              q.push(t->left);
              if(t->right)
              q.push(t->right);
          }
          lefttoright=!lefttoright;
          for(int &it: temp)
            ans.push_back(it);
        }
    return ans;
    }
};

//leetcode same question just return in 2d vector
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //answer vector
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        //tell with size we move now
        bool lefttoright=true;
        //queue for level order traversal
        queue<TreeNode *>q;
        q.push(root); //pushing the root in q
        while(!q.empty()){
            int sz=q.size();//size of q to traversal
            //temp vector for store the level
            vector<int>level(sz);
            
            //run a loop for n size and insert it left and right 
            for(int i=0;i<sz;i++){
                TreeNode *t=q.front();
                q.pop();
                //now check the lefttoright and modified the index 
                int idx=lefttoright?i:sz-1-i;
                //store in level vector
                level[idx]=t->val;
                //push left and right in queue if they have
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            //after end of for loop change the direction 
            lefttoright=!lefttoright;
            //push the level in the ans vector
            ans.push_back(level);
        }
        return ans;
    }
};