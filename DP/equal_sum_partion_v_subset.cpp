//recursion + memoization
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2==1)
            return false;
        sum=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return checksum(nums,n,sum,dp);
    }
    bool checksum(vector<int>& nums,int n, int sum,vector<vector<int>>&dp){
        if(sum==0)
            return true;
        if(n==0)
            return false;
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        if(nums[n-1]>sum)
            return dp[n][sum]=checksum(nums,n-1,sum,dp);
        
        return dp[n][sum]=(checksum(nums,n-1,sum,dp) || checksum(nums,n-1,sum-nums[n-1],dp));
    }
};
//optimal solution using iterator
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2==1)
            return false;
        sum=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return checksum(nums,n,sum,dp);
    }
    bool checksum(vector<int>& nums,int n, int sum,vector<vector<int>>&dp){
        if(sum==0)
            return true;
        if(n==0)
            return false;
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        if(nums[n-1]>sum)
            return dp[n][sum]=checksum(nums,n-1,sum,dp);
        
        return dp[n][sum]=(checksum(nums,n-1,sum,dp) || checksum(nums,n-1,sum-nums[n-1],dp));
    }
};

//optimal solution

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum%2==1)
            return false;
        int half=sum/2;
        
        //optimal solution
       vector<bool>prev(half+1,false),cur(half+1);
      
        for(int i=1;i<=n;i++){
            prev[0]=true;
            for(int j=1;j<=half;j++){
                if(j>=nums[i-1])
                   cur[j]=prev[j]|prev[j-nums[i-1]]; 
                else
                   cur[j]=prev[j];
            }
            prev=cur;
        }
        return prev[half];
    }
};