class Solution {
public:
    int fun(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        //base case
        
        //both string exhausted
        if(i<0 && j<0)return true;
        //s string exhausted and the t string remain then
        if(i<0 && j>=0)return false;
        //t string exhausted and s string have character now we have to check for *
        if(j<0 && i>=0){
            //now we have to check the remain character in string is * so it will equal to empty string
            for(int it=0;it<=i;it++){
                if(s[it]!='*')
                    return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        //all cases 
        //string match or it have ?
        if(s[i]==t[j] || s[i]=='?')
            return dp[i][j]=fun(i-1,j-1,s,t,dp);
      if(s[i]=='*')
            return dp[i][j]=fun(i-1,j,s,t,dp) || fun(i,j-1,s,t,dp);
      
         return dp[i][j]=false;  
    }
    
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return fun(m-1,n-1,p,s,dp);
    }
};


//tabular dp
//purily modified the above recursion+memoization code

//base  case become initilization and remain same

class Solution {
public:
    int fun(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        //base case
        
        //both string exhausted
        if(i==0 && j==0)return true;
        //s string exhausted and the t string remain then
        if(i==0 && j>0)return false;
        //t string exhausted and s string have character now we have to check for *
        if(j==0 && i>0){
            //now we have to check the remain character in string is * so it will equal to empty string
            for(int it=0;it<i;it++){
                if(s[it]!='*')
                    return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        //all cases 
        //string match or it have ?
        if(s[i-1]==t[j-1] || s[i-1]=='?')
            return dp[i][j]=fun(i-1,j-1,s,t,dp);
      if(s[i-1]=='*')
            return dp[i][j]=fun(i-1,j,s,t,dp) || fun(i,j-1,s,t,dp);
      
         return dp[i][j]=false;  
    }
    
    bool isMatch(string t, string s) {
        int n=t.length();
        int m=s.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
              if(i==0 && j==0)dp[i][j]=true;
             if(i==0 && j>0)dp[i][j]=false;
            if(j==0 && i>0){
                dp[i][j]=true;
            for(int it=0;it<i;it++){
                if(s[it]!='*')
                    dp[i][0]=false;
                }
              }
        }
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                 if(s[i-1]==t[j-1] || s[i-1]=='?')
             dp[i][j]=dp[i-1][j-1];
               else if(s[i-1]=='*')
             dp[i][j]=dp[i-1][j] || dp[i][j-1];
            else
             dp[i][j]=false;  
            }
        }
        
      return dp[m][n];
    }
};