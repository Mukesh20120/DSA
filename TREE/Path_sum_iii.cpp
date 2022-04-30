//brute force giving tle dfs traversal

class Solution {
    //makeing a global variable for store the total
    int total=0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        //if we have nothing
        if(root==NULL)return 0;
        //we will find the path for target
        //pasing root node /targetsum /and cur sum
        findpath(root,targetSum,0); //this is check from root 
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        
        return total;
    }
    void findpath(TreeNode *root,int tar,int sum){
        //we do post order traversal
        if(root==NULL)
            return;
        //adding value into sum
        sum+=root->val;
        //check if equal to target or not
        if(sum==tar)
            total++;
        findpath(root->left,tar,sum);
        findpath(root->right,tar,sum);
    }
};


//using unordered hash map foundation question is subarray sum equal to k

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define ll long long
class Solution {
    int total=0;
public:
    int pathSum(TreeNode* root, int targetSum) {
        //checking for root
        if(root==NULL)
            return 0;
        unordered_map<ll,int>mp;
        mp[0]++;
        findpathsum(root,targetSum,0,mp);
        return total;
    }
    void findpathsum(TreeNode* root,int k,ll sum,unordered_map<ll,int>&mp){
        if(root==NULL)
            return;
        sum+=root->val;
        if(mp.find(sum-k)!=mp.end())
            total+=mp[sum-k];
        mp[sum]++;
        findpathsum(root->left,k,sum,mp);
        findpathsum(root->right,k,sum,mp);
        mp[sum]--;
    }
};


