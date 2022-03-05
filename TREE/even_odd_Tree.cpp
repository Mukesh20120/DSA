/*
1.method The brute approach will be store the tree in 2d matrix
and check for the given condition that are asked 
2.method 
 optimal solution TC=O(no.of.nodes)
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        //simple level order traversal
        queue<TreeNode*>q;
        q.push(root);
        int level=0; //check for the level
        while(!q.empty()){
            int n=q.size();
            int pre=-1;//for even level order
            int pos=INT_MAX;
            for(int i=0;i<n;i++){
                TreeNode *node=q.front();
                q.pop();
                if(level%2==0){
                    if(pre >= node->val || node->val%2==0)
                        return false;
                    pre=node->val;
                }
                else{
                    if(pos <= node->val || node->val%2==1)
                        return false;
                    pos=node->val;
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            level++;
        }
        return true;
    }
};