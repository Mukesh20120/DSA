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