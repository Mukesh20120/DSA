/*
easy question just required level order traversal
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
      
        queue<TreeNode*>q;
        q.push(root);
        int level=0,maxi=INT_MIN,ans;
        while(!q.empty()){
            int n=q.size();
             level++;
            int sum=0;
            for(int i=0;i<n;i++){
                TreeNode *node=q.front();
                q.pop();
                sum+=node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(sum > maxi){
                maxi=sum;
                ans=level;
            }
                
        }
        return ans;
    }
};