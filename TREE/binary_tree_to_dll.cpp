//brute force approach using extra space to store the nodes in order


// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void Inorder(Node *root,vector<Node*>&num){
        if(root==NULL)return;
        Inorder(root->left,num);
        num.push_back(root);
        Inorder(root->right,num);
    }
    Node * bToDLL(Node *root)
    {
      //let store arr the nodes in inorder
      if(!root->left && !root->right)return root;
      vector<Node*>nodes;
      Inorder(root,nodes);
      
      Node *p=NULL;
      int n=nodes.size();
      for(int i=0;i<n;i++){
          nodes[i]->left=p;
          nodes[i]->right=i+1==n?NULL:nodes[i+1];
          p=nodes[i];
      }
      return nodes[0];
    }
};


//optimal solution using pointer prev and head only and auxilary extra space
class Solution
{   private:
     Node *prev=NULL;
     Node *head;
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    void Inorder(Node *root){
        if(root==NULL)return;
        Inorder(root->left);
        
        
        if(prev==NULL)head=root;
        root->left=prev;
        if(prev)prev->right=root;
        prev=root;
        
        
        Inorder(root->right);
    }
    Node * bToDLL(Node *root)
    {
      //let store arr the nodes in inorder
      if(!root->left && !root->right)return root;
      Inorder(root);
      return head;
    }
};