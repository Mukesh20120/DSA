//recursion + memoization code version of longest common subsequence

class Solution {
    private:
    int dp[501][501];
public:
    int minDistance(string word1, string word2) {
       //longest common subsequence length
        int n=word1.length();
        int m=word2.length();
        memset(dp,-1,sizeof(dp));
        int cnt=helper(word1,word2,n,m);
      return (n+m)-(2*cnt);
    }
    int helper(string a,string b,int n,int m){
        if(n==0 || m==0)
            return 0;
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(a[n-1]==b[m-1])
            return dp[n][m]=helper(a,b,n-1,m-1)+1;
        
        return dp[n][m]=max(helper(a,b,n-1,m),helper(a,b,n,m-1));
    }
};

//optimized code of above method

class Solution {
public:
    int minDistance(string a, string b) {
       //longest common subsequence length
        int n=a.length();
        int m=b.length(); 
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                 else
                  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
       return (n+m)-(2*dp[n][m]); 
    }
    
};

//space optimized of the above code
class Solution {
public:
    int minDistance(string a, string b) {
       //longest common subsequence length
        int n=a.length();
        int m=b.length(); 
        vector<int>prev(m+1,0),cur(m+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                 if(a[i-1]==b[j-1])
                    cur[j]=prev[j-1]+1;
                 else
                  cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
       return (n+m)-(2*prev[m]); 
    }
    
};