class Solution {
    private:
    int dp[601][101][101];
    //as given length can be 600 and the string length can be 100
public:
    int findMaxForm(vector<string>& strs, int m, int y) {
        //we store the count of zero and one in 2d vector and then question boil down to knapsack
        int n=strs.size();
        //initilized n*2 vector with 0
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>nums(n,vector<int>(2,0));
        //filling the vector
        for(int i=0;i<n;i++){
            int l=strs[i].length();
            for(int j=0;j<l;j++){
                nums[i][strs[i][j]-'0']++;
            }
        }
        //now question boil down to knapsack 
        return knapsack(nums,m,y,n);
    }
    int knapsack(vector<vector<int>>&nums,int z,int o,int n){
        if(z==0 && o==0)
            return 0;
        if(z<0 || o<0 || n==0)
            return 0;
        
        if(dp[n][z][o]!=-1)
            return dp[n][z][o];
        //here we have two case one take and other not take
        //take when
        if(z>=nums[n-1][0] && o>=nums[n-1][1])
            return dp[n][z][o]=max(knapsack(nums,z-nums[n-1][0],o-nums[n-1][1],n-1)+1,knapsack(nums,z,o,n-1));
        
        return dp[n][z][o]=knapsack(nums,z,o,n-1);
    }
};

//optimal solution using iterator 

class Solution {
public:
    int findMaxForm(vector<string>& strs, int z, int o) {
         int n=strs.size();
        vector<vector<int>>nums(n,vector<int>(2,0));
        //filling the vector
        for(int i=0;i<n;i++){
            int l=strs[i].length();
            for(int j=0;j<l;j++){
                nums[i][strs[i][j]-'0']++;
            }
        }
        
        //making 3d vector same as memoization
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(z+1,vector<int>(o+1)));
        //as we have initilized all the value with 0
        for(int i=0;i<=n;i++){
            for(int j=0;j<=z;j++){
                for(int k=0;k<=o;k++){
                if(i==0 || j==0 && k==0)
                    dp[i][j][k]=0;
                    //as we initilized already now we directly take or not take
               else if(j>=nums[i-1][0] && k>=nums[i-1][1])
                    dp[i][j][k]=max(dp[i-1][j-nums[i-1][0]][k-nums[i-1][1]]+1,dp[i-1][j][k]);
               else
                    dp[i][j][k]=dp[i-1][j][k];
                }
            }
        }
        return dp[n][z][o];
    }
};