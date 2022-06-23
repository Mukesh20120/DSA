//using map store x axis and node and do level order traversal easy question

class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool helper(struct Node *n1,struct Node *n2){
        if(!n1 && !n2)return true;
        if(!n1 || !n2)return false;
        if(n1->data!=n2->data)return false;
        
        return helper(n1->left,n2->right) && helper(n1->right,n2->left);
    }
    
    bool isSymmetric(struct Node* root)
    {
        if(root==NULL)
        return true;
	  return helper(root->left,root->right);
    }
};