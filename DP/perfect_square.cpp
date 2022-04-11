//naive approach using recursion question boil down to unbounded knapsack
class Solution {
public:
    int numSquares(int n) {
        //making array 
        vector<int>nums;
        for(int i=1;i*i<=n;i++){
            nums.push_back(i*i);
        }
        //question boil down to knapsack
        return count(nums,n,nums.size()-1);
    }
    int count(vector<int>&nums,int sum,int n){
        if(sum==0)
            return 0;
        if(n<0)
            return 1e8;
        //if element is greater than we not take
        if(nums[n]>sum)
            return count(nums,sum,n-1);
        return min(count(nums,sum,n-1),1+count(nums,sum-nums[n],n));
    }
};
//memoization of above code 
class Solution {
public:
    int numSquares(int n) {
        //making array 
        vector<int>nums;
        for(int i=1;i*i<=n;i++){
            nums.push_back(i*i);
        }
        //question boil down to unboundedknapsack
        //memoized the code
        int sz=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return count(nums,n,sz-1,dp);
    }
    int count(vector<int>&nums,int sum,int n,vector<vector<int>>&dp){
        if(sum==0)
            return 0;
        if(n<0)
            return 1e8;
        if(dp[sum][n]!=-1)
            return dp[sum][n];
        //if element is greater than we not take
        if(nums[n]>sum)
            return dp[sum][n]=count(nums,sum,n-1,dp);
        return dp[sum][n]=min(count(nums,sum,n-1,dp),1+count(nums,sum-nums[n],n,dp));
    }
};

//optimal solution using tabular dp unbounded knapsack
class Solution {
public:
    int numSquares(int n) {
        //making array 
        vector<int>nums;
        for(int i=1;i*i<=n;i++){
            nums.push_back(i*i);
        }
        //question boil down to unboundedknapsack
        return count(nums,n);
    }
    int count(vector<int>&nums,int tar){
         int n=nums.size();
        int dp[n+1][tar+1];
        //initilizing
        for(int j=0;j<=tar;j++)
            dp[0][j]=1e8;
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
       for(int i=1;i<=n;i++){
           for(int j=1;j<=tar;j++){
                if(nums[i-1]>j)
                dp[i][j]=dp[i-1][j];
               else
             dp[i][j]=min(dp[i-1][j],1+dp[i][j-nums[i-1]]);
           }
       }
        return dp[n][tar];
    }
};




//other way to solve question
//recursion approach                      tech dose yt
class Solution {
public:
    int numSquares(int n) {
        //recursion solution
    return count(n);
    }
    int count(int n){
        if(n<=3)
            return n;
        int ans=n;
        for(int i=1;i*i<=n;i++)
            ans=min(ans,1+count(n-i*i));
        
        return ans;
    }
};

//memoization above code
class Solution {
public:
    int numSquares(int n) {
        //recursion solution
        vector<int>dp(n+1,-1);
    return count(n,dp);
    }
    int count(int n,vector<int>&dp){
        if(n<=3)
            return n;
        
        if(dp[n]!=-1)return dp[n];
        int ans=n;
        for(int i=1;i*i<=n;i++)
            ans=min(ans,1+count(n-i*i,dp));
        
        return dp[n]=ans;
    }
};

//optimal approach using tabluar form
class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        dp[0]=0;
        for(int i=1;i<=n;i++){
            dp[i]=i;
           for(int j=1;j*j<=i;j++){
            int sz=j*j;
            dp[i]=min(dp[i],1+dp[i-sz]);
            }
        }
        return dp[n];
    }
};

