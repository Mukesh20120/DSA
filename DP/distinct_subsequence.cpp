class Solution {
    public:
    int fun(string &s,string &t,int i,int j){
        //base case if we at the end of t string means we match 
        //all the character of t string from s
        if(j<0)return 1;
        //if j is still have character but we reach the end of the first string
        if(i<0)return 0;
        
        //two choices
        
        //if we get the matching character
        if(s[i]==t[j]){
            //we move ahead on both string and we not taking the match string 
            return fun(s,t,i-1,j-1)+fun(s,t,i-1,j);
        }
            return fun(s,t,i-1,j);//character not match we check next character
    }

    int numDistinct(string s, string t) {
      int n=s.length();
      int m=t.length();
        return fun(s,t,n-1,m-1);
    }
};


//2 method memoization above code
class Solution {
    int dp[1001][1001];
    public:
    int fun(string &s,string &t,int i,int j){
        //base case if we at the end of t string means we match 
        //all the character of t string from s
        if(j<0)return 1;
        //if j is still have character but we reach the end of the first string
        if(i<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        //two choices
        //if we get the matching character
        if(s[i]==t[j]){
            //we move ahead on both string and we not taking the match string 
            return dp[i][j]=fun(s,t,i-1,j-1)+fun(s,t,i-1,j);
        }
            return dp[i][j]=fun(s,t,i-1,j);//character not match we check next character
    }

    int numDistinct(string s, string t) {
      int n=s.length();
      int m=t.length();
        memset(dp,-1,sizeof(dp));
        return fun(s,t,n-1,m-1);
    }
};

//3 method tabulation form
class Solution {
public:
    int numDistinct(string s, string t) {
      int n=s.length();
      int m=t.length();
      //making tabular for dp
        vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        //initilize j=0 from 1 and i=0 0
        //as we filled the dp vector with 0 so we have to initilized it with 1 only
        for(int i=0;i<n;i++)
            dp[i][0]=1;
        
        //same option in recursion 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return (int)(dp[n][m]);
    }
};


//4 method making 1D dp
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<double>prev(m+1,0),cur(m+1,0);//length upto m
        prev[0]=cur[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                    cur[j]=prev[j-1]+prev[j];
                else
                    cur[j]=prev[j];
            }
            prev=cur;
        }
        return (int)(prev[m]);
    }
};