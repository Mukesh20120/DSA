class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(!root)return s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
              TreeNode *node=q.front();
              q.pop();
           if(node==NULL)s.append("#,");
           else
               s.append(to_string(node->val)+',');
           if(node){
               q.push(node->left);
               q.push(node->right);
           }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
         int n=data.size();
        if(n==0)return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode *root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node=q.front();
            q.pop();
            //for left child
            getline(s,str,',');
            if(str=="#")
                node->left=NULL;
            else{
                TreeNode *left=new TreeNode(stoi(str));
                node->left=left;
                q.push(left);
            }
            //for right child
            getline(s,str,',');
            if(str=="#")
                node->right=NULL;
            else{
                TreeNode *right=new TreeNode(stoi(str));
                node->right=right;
                q.push(right);
            }
        }
       return root; 
    }
};