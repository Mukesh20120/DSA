//recursion and memoization 

class Solution {
    private:
    int dp[13][10001];
public:
    int helper(vector<int>&nums,int sum,int n){
        //base case
        if(sum==0)
            return 0;
        if(n<0)
            return 1e8;
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        
        if(sum<nums[n])
            return dp[n][sum]=helper(nums,sum,n-1);
        
        return dp[n][sum]=min(1+helper(nums,sum-nums[n],n),helper(nums,sum,n-1));
    }
    int coinChange(vector<int>& coins, int amo) {
        //can be done using unbounded knapsack
        memset(dp,-1,sizeof(dp));
       int ans=helper(coins,amo,coins.size()-1);
       return ans==1e8?-1:ans;
    }
};

//optimal solution using dp

class Solution {
public:
    int coinChange(vector<int>& coins, int a) {
        int n=coins.size();
        int dp[n+1][a+1];
        //initilization
        //if j or sum==0 then we store 0
        //if i==0 means we are endof the list store max
        for(int i=0;i<=n;i++){
            for(int j=0;j<=a;j++){
                if(i==0 || j==0)
                dp[i][j]=(j==0)?0:INT_MAX-1;
            }
        }
        
        //now runnig the loop from 1
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a;j++){
                //copy all the code of the recursion nothing else
                if(j<coins[i-1])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
            }
        }
        return dp[n][a]==INT_MAX-1?-1:dp[n][a];
    }
};