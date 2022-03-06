/* 
doing by traversal
store in queue above row and make row and changing pointer
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        //when depth is 1 we have to change root
        if(depth==1){
          TreeNode *temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        //simply level order traversal
        int level=1;
        queue<TreeNode*>q; 
        q.push(root);
        //storing the last depth node below which new nodes added
        while(level!=depth-1){
            int n=q.size();
            level++;
            for(int i=0;i<n;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        //adding the new row and replacing the pointer
        while(!q.empty()){
            TreeNode *t=q.front();
            q.pop();
            TreeNode *l=new TreeNode(val);
            TreeNode *r=new TreeNode(val);
            l->left=t->left;
            r->right=t->right;
            t->left=l;
            t->right=r;
        }
        return root;
    }
};