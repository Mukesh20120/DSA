class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    
    void Inorder(Node *root,vector<int>&nums){
        if(root==NULL)
        return;
        Inorder(root->left,nums);
        nums.push_back(root->data);
        Inorder(root->right,nums);
    }
    
    vector<int> mtsv(vector<int>&a,vector<int>&b){
        int n=a.size();
        int m=b.size();
        vector<int>ans;
        int i=0,j=0;
        while(i<n && j<m){
            if(a[i]<b[j])
                ans.push_back(a[i++]);
            else
               ans.push_back(b[j++]);
        }
        for(;i<n;i++)
          ans.push_back(a[i]);
        for(;j<m;j++)
           ans.push_back(b[j]);
           
    return ans;
    }
    
    
    vector<int> merge(Node *root1, Node *root2)
    {
      //brute force approach using vector to store the element
      vector<int>a,b;
      Inorder(root1,a);
      Inorder(root2,b);
      
      //now we just need to merge two sorted list
      return mtsv(a,b);
    }
};
