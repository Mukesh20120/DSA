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