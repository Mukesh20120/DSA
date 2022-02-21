/* simply traverse throught bst and go left and right 
  if value is less the finding value we move right b/c we have to find the 
  greater value from the key
  if we found root value geater then we modified the ans and move to the left
  */
  
class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
       Node *ans=NULL;
       while(root){
           if(root->data <= x->data)
               root=root->right;
           else{
               ans=root;
              root=root->left;   
           }
       }
       return ans;
    }
};

