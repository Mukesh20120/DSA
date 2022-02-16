class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //constructing a map so we can easily find the element and index of inorder
        map<int,int>mp;
        int sz=inorder.size();
        for(int i=0;i<sz;i++)
             mp[inorder[i]]=i;
        TreeNode *root=build(preorder,0,preorder.size()-1,inorder,0,sz-1,mp);
        return root;
    }
    TreeNode *build(vector<int>&pre,int ps,int pe,vector<int>&ino,int is,int ie,map<int,int>&mp){
        if(ps>pe || is>ie)return NULL;
        //as preorder is root left right then 
        TreeNode *node=new TreeNode(pre[ps]);
        int ind=mp[node->val];
        int diff=ind-is;
        
        node->left=build(pre,ps+1,ps+diff,ino,is,ind-1,mp);
        node->right=build(pre,ps+diff+1,pe,ino,ind+1,ie,mp);
        
        return node;
    }
}
;
