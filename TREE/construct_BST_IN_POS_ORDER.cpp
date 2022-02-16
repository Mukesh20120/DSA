class Solution {
public:
    TreeNode* buildTree(vector<int>& ino, vector<int>& pos) {
        //making a map to easily find element and its index
        map<int,int>mp;
        for(int i=0;i<ino.size();i++)
             mp[ino[i]]=i;
        //in postorder right left root we will start from end
        TreeNode *root=build(pos,0,pos.size()-1,ino,0,ino.size()-1,mp);
        
        return root;
    }
    TreeNode * build(vector<int>&pos,int ps,int pe,vector<int>&ino,int is,int ie,map<int,int>&mp){
        if(is>ie || pe<ps)return NULL;
        
        TreeNode *node=new TreeNode(pos[pe]);
        int ind=mp[node->val];
        int diff=ind-is;
        
        node->left=build(pos,ps,ps+diff-1,ino,is,ind-1,mp);
        node->right=build(pos,ps+diff,pe-1,ino,ind+1,ie,mp);
      
        
        return node;
    }
    
};
