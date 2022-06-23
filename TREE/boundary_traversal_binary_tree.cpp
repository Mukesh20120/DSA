
class Solution {
public:
   bool isLeaf(Node *root){
       if(!root->left && !root->right)
         return true;
    return false;
   }
    void leftboundary(Node *root,vector<int>&ans){
        //we will directly push left in our answer
       Node *cur=root->left;
       while(cur){
           if(!isLeaf(cur))
              ans.push_back(cur->data);
          if(cur->left)
             cur=cur->left;
          else
             cur=cur->right;
       }
    }
    
    void leafnodes(Node *root,vector<int>&ans){
        if(isLeaf(root)){
          ans.push_back(root->data);
          return;
        }
        if(root->left)leafnodes(root->left,ans);
        if(root->right)leafnodes(root->right,ans);
    }
    
    void rightboundary(Node *root,vector<int>&ans){
        vector<int>temp;//as we need in reverse order
        Node *cur=root->right;
        while(cur){
            if(!isLeaf(cur))
              temp.push_back(cur->data);
            if(cur->right)
            cur=cur->right;
            else
            cur=cur->left;
        }
        //store in answer vector in reverse order
          for(int i=temp.size()-1;i>=0;i--)
             ans.push_back(temp[i]);
    }
    
    vector <int> boundary(Node *root)
    {
      vector<int>ans;
       ans.push_back(root->data);
      if(isLeaf(root))
      return ans;
     
      leftboundary(root,ans);
      leafnodes(root,ans);
      rightboundary(root,ans);
      
      return ans;
    }
};
