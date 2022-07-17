//recrusion approach 

class Solution {
    private:
    int di[4]={0,0,-1,1};
    int dj[4]={-1,1,0,0};
public:
    int findPaths(int m, int n, int mm, int i, int j) {
        //boundary case
        if(mm<0)
            return 0;
        if(i<0 || i>=m || j<0 || j>=n)
            return 1;
        //we move in four direction and add the in ans
        int ans=0;
        for(int id=0;id<4;id++)
            ans+=findPaths(m,n,mm-1,i+di[id],j+dj[id]);
        return ans;
    }
};


//recursion + memoization approach 

class Solution {
    private:
    int di[4]={0,0,-1,1};
    int dj[4]={-1,1,0,0};
    int dp[51][51][51];
    int mod=1e9+7;
public:
    int findPaths(int m, int n, int mm, int i, int j) {
        memset(dp,-1,sizeof(dp));
       return helper(m,n,mm,i,j);
    }
     int helper(int m, int n, int mm, int i, int j) {
        //boundary case
        if(mm<0)
            return 0;
        if(i<0 || i>=m || j<0 || j>=n)
            return 1;
        if(dp[i][j][mm]!=-1)
            return dp[i][j][mm];
        //we move in four direction and add the in ans
        long long ans=0;
        for(int id=0;id<4;id++)
            ans+=helper(m,n,mm-1,i+di[id],j+dj[id]);
       
         return dp[i][j][mm]=ans%mod;
    }
};