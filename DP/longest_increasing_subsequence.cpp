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

//tabular form 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int len=dp[i+1][j+1];
                if(j==-1 || nums[i]>nums[j]){
                    len=max(len,1+dp[i+1][i+1]);
                }
                dp[i][j+1]=len;
            }
        }
        return dp[0][0];
    }
};
//space optimized above code using prev and cur 1d vector
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>prev(n+1,0);
        vector<int>cur(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int len=prev[j+1];
                if(j==-1 || nums[i]>nums[j]){
                    len=max(len,1+prev[i+1]);
                }
                cur[j+1]=len;
            }
            swap(cur,prev);
        }
        return prev[0];
    }
};

//other solution using 1 d vector to store the maximum value
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //we maintain a variable to store the maximum
        int maxi=1;
        //make a 1d array to store
        int n=nums.size();
        //as maximum lenght of subsequence will be 1
        vector<int>dp(n,1);
        //running two loop find max and update the dp array
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                //previous is less than current value
                if(nums[prev]<nums[i]){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            maxi=max(dp[i],maxi);
        }
        return maxi;
    }
};