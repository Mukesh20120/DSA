//recursion approach

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void helper(Node *root,int level,vector<int>&ans){
        if(root){
            if(level==ans.size())
              ans.push_back(root->data);
            helper(root->right,level+1,ans);
            helper(root->left,level+1,ans);
        }
    }
    
    vector<int> rightView(Node *root)
    {
      vector<int>ans; //store answer
      helper(root,0,ans);//passing in function
      return ans;
    }
};

//using queue for level order traversal and map for store the first right value

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
      vector<int>ans;
      if(root==NULL)return ans;
      map<int,int>hash;
      queue<pair<int,Node*>>q;
      q.push({0,root});
      while(!q.empty()){
          auto p=q.front();
          q.pop();
          Node *temp=p.second;
          int l=p.first;
          if(hash.find(l)==hash.end())
             hash[l]=temp->data;
          if(temp->right)
            q.push({l+1,temp->right});
          if(temp->left)
            q.push({l+1,temp->left});
      }
      for(auto &it: hash)
        ans.push_back(it.second);
    
    return ans;
    }
};


//optimizing above code does not taking any extra space of map

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
      vector<int>ans;
      if(root==NULL)return ans;
     // map<int,int>hash;
      queue<pair<int,Node*>>q;
      q.push({0,root});
      while(!q.empty()){
          auto p=q.front();
          q.pop();
          Node *temp=p.second;
          int l=p.first;
        //   if(hash.find(l)==hash.end())
        //     hash[l]=temp->data;
          if(l==ans.size())
             ans.push_back(temp->data);
          if(temp->right)
            q.push({l+1,temp->right});
          if(temp->left)
            q.push({l+1,temp->left});
      }
    //   for(auto &it: hash)
    //     ans.push_back(it.second);
    
    return ans;
    }
};