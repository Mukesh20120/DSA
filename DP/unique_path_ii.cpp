//recursion + memoization approach

class Solution {
    private:
    int n,m;
    int dp[101][101];
public:
    int helper(vector<vector<int>>&nums,int i,int j){
        //boundary condition
        if(i>=n || j>=m || nums[i][j])
            return 0;
        if(i==n-1 && j==m-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
     return dp[i][j]=helper(nums,i+1,j)+helper(nums,i,j+1);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& nums) {
        n=nums.size();
        m=nums[0].size();
        memset(dp,-1,sizeof(dp));
        if(nums[n-1][m-1])
            return 0;
        return helper(nums,0,0);
    }
};