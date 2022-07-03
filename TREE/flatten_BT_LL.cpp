//1 method recursive
class Solution {
public:
       TreeNode * prev=NULL;
    void flatten(TreeNode* root) {
        if(!root)return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};

//2 method using extra space

class Solution
{
    public:
    void helper(Node *root,vector<Node*>&temp){
        if(root==NULL)return;
        temp.push_back(root);
        helper(root->left,temp);
        helper(root->right,temp);
    }
    
    void flatten(Node *root)
    {
        //preorder root left right
        vector<Node*>temp;
        helper(root,temp);
        int n=temp.size();
        for(int i=0;i<temp.size();i++){
            temp[i]->left=NULL;
            temp[i]->right=i+1==n?NULL:temp[i+1];
        }
       root=temp[0];
    }
};


