//recursion + memoization code

class Solution {
    private:
      int dp[21][31];
public:
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,s,p);
    }
    bool helper(int i,int j,string s,string p){
        //base case
        if(j==p.length())
            return i==s.length();
        if(i<s.length() && dp[i][j]!=-1)
            return dp[i][j];
        //now the match function like variable
        bool firstmatch=i<s.length() && (s[i]==p[j] || p[j]=='.');
        
        bool ans=false;
        //now we have two cases second character is *
        if(j+1<p.length() && p[j+1]=='*')
            ans= firstmatch && helper(i+1,j,s,p) || helper(i,j+2,s,p);
        else
            ans=firstmatch && helper(i+1,j+1,s,p);
        
        return dp[i][j]=ans;
    }
};


//optimal solution filling dp

class Solution {
public:
    bool isMatch(string s, string p) {
       int n=s.length();
        int m=p.length();
      vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        //base case same as recursion
        dp[n][m]=true;
        
        //we use two loop 
        for(int i=n;i>=0;i--){
            //j start from last second index as we check two ahead
            for(int j=m-1;j>=0;j--){
                
       bool firstmatch= i<n && (s[i]==p[j] || p[j]=='.');
        //now we have two cases second character is *
        if(j+1<m && p[j+1]=='*')
            dp[i][j]= dp[i][j+2] || firstmatch && dp[i+1][j];
        else
            dp[i][j]=(firstmatch && dp[i+1][j+1]);
            } 
        }
        return dp[0][0];
    }

};