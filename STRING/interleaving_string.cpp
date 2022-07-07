class Solution {
public:
    bool compare(string &res,string &s3){
        if(res.length()!=s3.length())return false;
        for(int i=0;i<res.length();i++)
            if(res[i]!=s3[i])
                return false;
        return true;
    }
    
    bool helper(string &a,int i,string &b,int j,string res,string &s3){
        if(compare(res,s3) && i==a.length() && j==b.length())
            return true;
        bool ans=false;
        if(i<a.length())
            ans|=helper(a,i+1,b,j,res+a[i],s3);
       
        if(j<b.length())
            ans|=helper(a,i,b,j+1,res+b[j],s3);
        
        return ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        //recursion approach
        if(s1.length()+s2.length()!=s3.length())
            return false;
        return helper(s1,0,s2,0,"",s3);
    }
};

//memoization technique

class Solution {
    private:
      int dp[101][101];
public:
    bool compare(string res,string s3){
        if(res.length()!=s3.length())return false;
        for(int i=0;i<res.length();i++)
            if(res[i]!=s3[i])
                return false;
        return true;
    }
    
    bool helper(string &a,int i,string &b,int j,int k,string &s3){
        
        //checking if i equal to length of a
        if(dp[i][j]!=-1)return dp[i][j];
        
        //base case
        if(i==a.length() && j==b.length() && k==s3.length())return true;
        
       bool ans=false;
        
        if(i!=a.length())
            if(a[i]==s3[k])
                ans|=helper(a,i+1,b,j,k+1,s3);
        if(j!=b.length())
            if(b[j]==s3[k])
                ans|=helper(a,i,b,j+1,k+1,s3);
        
        return dp[i][j]=ans;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        //recursion approach
        if(s1.length()+s2.length()!=s3.length())
            return false;
        memset(dp,-1,sizeof(dp));
        return helper(s1,0,s2,0,0,s3);
    }
};

//dp solution 2d vector
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length();
        int m=s2.length();
        if(s3.length()!=n+m)return false;
        //declare a 2d vector
        vector<vector<bool>>dp(n+1,vector<bool>(m+1));
        
        //loop on vector
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                //base cases
                if(i==0 && j==0)
                    dp[i][j]=true;
                else if(i==0)
                    dp[i][j]=dp[i][j-1] && s2[j-1]==s3[i+j-1];
                else if(j==0)
                    dp[i][j]=dp[i-1][j] && s1[i-1]==s3[i+j-1];
                else
                    dp[i][j]=dp[i][j-1] && s2[j-1]==s3[i+j-1] || dp[i-1][j] && s1[i-1]==s3[i+j-1];
            }
        }
        return dp[n][m];
    }
};

//1d dp

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.length();
        int m=s2.length();
        if(s3.length()!=n+m)return false;
        //declare a 2d vector
       vector<bool>dp(m+1);
        
        //loop on vector
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                //base cases
                if(i==0 && j==0)
                    dp[j]=true;
                else if(i==0)
                    dp[j]=dp[j-1] && s2[j-1]==s3[i+j-1];
                else if(j==0)
                    dp[j]=dp[j] && s1[i-1]==s3[i+j-1];
                else
                    dp[j]=dp[j-1] && s2[j-1]==s3[i+j-1] || dp[j] && s1[i-1]==s3[i+j-1];
            }
        }
        return dp[m];
    }
};