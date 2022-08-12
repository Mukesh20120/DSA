//recursion approach

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target==0)
            return 1;
        int res=0;
        for(int i: nums){
            if(i<=target)
               res+=combinationSum4(nums,target-i);
        }
        return res;
    }
};

//memoization above code
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return helper(nums,target,dp);
    }
    int helper(vector<int>&nums,int t,vector<int>&dp){
        if(t==0)
            return 1;
        if(dp[t]>-1)return dp[t];
        int res=0;
        for(int i: nums){
            if(i<=t)
               res+=helper(nums,t-i,dp);
        }
        return dp[t]=res;
    }
};

//bottom up 
//remember to use unsigned int so we not get integer overflow

class Solution {
public:
    int combinationSum4(vector<int>& nums, int t) {
        vector<unsigned int>dp(t+1);
        dp[0]=1;
        for(int i=1;i<=t;i++){
            for(int j: nums){
                if(i>=j)
                  dp[i]+=dp[i-j];
            }
        }
        return dp[t];
    }
};