// concept is little bit simlar we always go to the mid point 
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
    TreeNode *build(vector<int>&nums,int low,int high){
        if(low<=high){
            int mid=low+(high-low)/2;
            TreeNode *root=new TreeNode(nums[mid]);
            root->left=build(nums,low,mid-1);
            root->right=build(nums,mid+1,high);
            return root;
        }
        return NULL;
    }
};

/* 2 method little bit simlar as linked list here we make vector each time and pasing 


*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)return NULL;
        if(nums.size()==1)return new TreeNode(nums[0]);
        
        int mid=nums.size()/2;
        TreeNode *root=new TreeNode(nums[mid]);
        
        vector<int>rleft(nums.begin(),nums.begin()+mid);
        vector<int>rright(nums.begin()+mid+1,nums.end());
        root->left=sortedArrayToBST(rleft);
        root->right=sortedArrayToBST(rright);
        return root;
    }
};


