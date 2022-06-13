//recursion approach
class Solution {
   
public:
    int minimumTotal(vector<vector<int>>& triangle) {
      return solve(triangle,0,0);
    }
    int solve(vector<vector<int>>&tri,int i,int j){
        //base case
        if(i==tri.size()-1 && j<tri[i].size())
            return tri[i][j];
        if(j==tri[i].size())
            return INT_MAX;
        //two cases
        int a=solve(tri,i+1,j)+tri[i][j];
        int b=solve(tri,i+1,j+1)+tri[i][j];
        
        return min(a,b);
    }
};


//memoization above code
class Solution {
   private:
    int dp[201][201];
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof(dp));
      return solve(triangle,0,0);
    }
    int solve(vector<vector<int>>&tri,int i,int j){
        //base case
        if(i==tri.size()-1 && j<tri[i].size())
            return tri[i][j];
        if(j==tri[i].size())
            return INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        //two cases
        int a=solve(tri,i+1,j)+tri[i][j];
        int b=solve(tri,i+1,j+1)+tri[i][j];
        
        return dp[i][j]=min(a,b);
    }
};

//using dp approach
class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
        int dp[n][n];
        //initilization with same row of tri in dp
        for(int j=0;j<n;j++)
            dp[n-1][j]=tri[n-1][j];
        //using two loop filling the dp array
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int a=dp[i+1][j];
                int  b=dp[i+1][j+1];
                dp[i][j]=min(a,b)+tri[i][j];
            }
        }
        return dp[0][0];
    }
};