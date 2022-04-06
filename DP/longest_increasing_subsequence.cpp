class Solution {
public:
    int helper(int prev,vector<int>&nums,int n,int i){
        //base case
        if(i==n)return 0;
        //we have two option first we not take and then we take
        //not take
        int len=helper(prev,nums,n,i+1);
        if(prev==-1 || nums[prev]<nums[i] )
            return len=max(len,1+helper(i,nums,n,i+1));
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        //passing to helper(previous index,vector,size,index)
        return helper(-1,nums,nums.size(),0);
    }
};

//memoization above code 
class Solution {
public:
    int helper(int prev,vector<int>&nums,int n,int i,vector<vector<int>>&dp){
        //base case
        if(i==n)return 0;
        //we have two option first we not take and then we take
        //not take
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int len=helper(prev,nums,n,i+1,dp);
        if(prev==-1 || nums[prev]<nums[i] )
            return len=max(len,1+helper(i,nums,n,i+1,dp));
        return dp[i][prev+1]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        //passing to helper(previous index,vector,size,index)
        //as prev and index is changing we need 2d array to memoized
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(-1,nums,n,0,dp);
    }
};