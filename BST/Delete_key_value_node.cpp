/*
  concept we do this problem by recursion
  step1 base case
         1.check root is null or not
         2. check for leaf node see code for reference  (imp)
             the deleting part is done by 2 base case
    
    step 2 finding the key value node 
         we have 3 case 1 key greater than node->val
                        2 key less than node->val
                        3 key equal to the node->val found it
          now 3 case arise we have to delete the node by we can't directly delete it
          we have to maintain the binary property 
            check height which one greater left or right
            then make a node to store the value we go left and then right right right
            until we found the null inord. and copy the value of last left -r-r-r leaf node
            to the node and now we have to delete the copy node so we pass the root and leaf
            node to the function again
            
        same if the right height is greater than the left height 
        all step are same as done in left
 */
class Solution {
public:
    int height(TreeNode *node){
        if(node==NULL)return 0;
        int x=height(node->left);
        int y=height(node->right);
        return x>y?x+1:y+1;
    }
    TreeNode* Inor(TreeNode *lchild){
        while(lchild && lchild->right){
            lchild=lchild->right;
        }
        return lchild;
    }
    TreeNode* presuc(TreeNode *rchild){
        while(rchild && rchild->left){
            rchild=rchild->left;
        }
        return rchild;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val==key && !root->left && !root->right){
            delete(root);
            return NULL;
        }
        TreeNode *node=root,*q;
            if(node->val > key)
              node->left=deleteNode(node->left,key);
            else if(node->val < key)
               node->right=deleteNode(node->right,key);
            else{
                if(height(node->left)>height(node->right)){
                    q=Inor(node->left);
                    node->val=q->val;
                    node->left=deleteNode(node->left,q->val);
                }
                else{
                    q=presuc(node->right);
                    node->val=q->val;
                    node->right=deleteNode(node->right,q->val);
                }
        }
        return root;
    }
};
