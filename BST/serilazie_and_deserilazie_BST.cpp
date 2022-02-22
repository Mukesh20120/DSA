class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(!root)return s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *p=q.front();
            q.pop();
            if(p)
                s=s.append(to_string(p->val)+',');
            else
                s+="#,";
            
            if(p){
                q.push(p->left);
                q.push(p->right);
            } 
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n=data.length();
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
            getline(s,str,',');
            if(str=="#")
                node->left=NULL;
            else{
                TreeNode *left=new TreeNode(stoi(str));
                node->left=left;
                q.push(left);
            }
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

