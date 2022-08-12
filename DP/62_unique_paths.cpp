class Solution {
public:
    int uniquePaths(int m, int n) {
       vector<vector<int>>dp(m,vector<int>(n,-1));
      return count(m-1,n-1,dp);
    }
    int count(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0)return 1;
        if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        int up=count(i-1,j,dp);
        int left=count(i,j-1,dp);
        return dp[i][j]=up+left;
    }
};

//using loop
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
       for(int i=0;i<m;i++)
           dp[i][0]=1;
       for(int j=0;j<n;j++)
           dp[0][j]=1;
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        
      return dp[m-1][n-1];
    }
    
};

//further space optimisation
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n,1),cur(n,0);
        //initilize 0 row and 0 col of dp
        for(int i=1;i<m;i++){
            cur[0]=1;
            for(int j=1;j<n;j++)
              cur[j]=cur[j-1]+prev[j];
         prev=cur;
        }
        return prev[n-1];
    }
};