class Solution{
    public:
    int giveheight(Node *root){
        if(root==NULL)return 0;
        int l=giveheight(root->left);
        int r=giveheight(root->right);
        return max(l,r)+1;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {  
        if(root==NULL)
        return true;
       //brute force approach 
       //find the left height and right height
       //check it difference 
       //move to other left and right
       //if any gave true return false
       int lh=giveheight(root->left);
       int rh=giveheight(root->right);
       //condition check
       if(abs(lh-rh)>1)return false;
       //now we check for root now check for left and right
       bool left=isBalanced(root->left);
       bool right=isBalanced(root->right);
       
       //if either of them return false return false
       if(!left || !right)
       return false;
       
       return true;
    }
};

//other solution using height function as a checking method

class Solution{
    public:
    
    //Function to check whether a binary tree is balanced or not.
    int helper(Node *root){
        if(root==NULL)return 0;
        //find left height
        int l=helper(root->left);
        if(l==-1)return -1;
        int r=helper(root->right);
        if(r==-1)return -1;
        if(abs(l-r)>1)return -1;
        
        return max(l,r)+1;
    }
    bool isBalanced(Node *root)
    {
        return helper(root)!=-1;
    }
};