//recursion solution reference from the delete operation of two stirng 
//which is based on longest common subsequence
//leetcode solution 4 and 5 reference

//recursion solution
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        //we directly return the ascii value
        //reference from the delete operation for two string
        //leetcode solution 4 and 5
        int n=s1.length();
        int m=s2.length();
        
        return helper(s1,s2,n,m);
    }
    int asciisum(string s,int n){
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=s[i];
        
        return sum;
    }
    
    int helper(string s1,string s2,int n,int m){
        //base case if any one of 0 then we return the all ascii sum
        if(n==0 || m==0){
            int sum=0;
            if(n)
                sum+=asciisum(s1,n);
            if(m)
                sum+=asciisum(s2,m);
            return sum;
        }
        
        //if both string character is equal then we don't add its ascii
        if(s1[n-1]==s2[m-1])
            return helper(s1,s2,n-1,m-1);
        
        return min(helper(s1,s2,n-1,m)+s1[n-1],helper(s1,s2,n,m-1)+s2[m-1]);
    }
};



//memoization above code  giving tle 

class Solution {
    private:
      int dp[1001][1001];
public:
    int minimumDeleteSum(string s1, string s2) {
        //we directly return the ascii value
        //reference from the delete operation for two string
        //leetcode solution 4 and 5
        int n=s1.length();
        int m=s2.length();
        memset(dp,-1,sizeof(dp));
        return helper(s1,s2,n,m);
    }
    int asciisum(string s,int n){
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=s[i];
        
        return sum;
    }
    
    int helper(string s1,string s2,int n,int m){
        //base case if any one of 0 then we return the all ascii sum
        if(n==0 || m==0){
            int sum=0;
            if(n)
                sum+=asciisum(s1,n);
            if(m)
                sum+=asciisum(s2,m);
            return sum;
        }
        if(dp[n][m]!=-1)
            return dp[n][m];
        //if both string character is equal then we don't add its ascii
        if(s1[n-1]==s2[m-1])
            return dp[n][m]=helper(s1,s2,n-1,m-1);
        
        return dp[n][m]=min(helper(s1,s2,n-1,m)+s1[n-1],helper(s1,s2,n,m-1)+s2[m-1]);
    }
};


//optimal approach of above code

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        //we directly return the ascii value
        //reference from the delete operation for two string
        //leetcode solution 4 and 5
        int n=s1.length();
        int m=s2.length();
       vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        //initialization 
        for(int i=1;i<=n;i++)
            dp[i][0]=dp[i-1][0]+s1[i-1];
        for(int j=1;j<=m;j++)
            dp[0][j]=dp[0][j-1]+s2[j-1];
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                   dp[i][j]=dp[i-1][j-1];
                else
                 dp[i][j]=min(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1]);
            }
        }
        return dp[n][m];
    }
};

//space optimized above code into 1d vector

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        //we directly return the ascii value
        //reference from the delete operation for two string
        //leetcode solution 4 and 5
        int n=s1.length();
        int m=s2.length();
       vector<int>prev(m+1,0),cur(m+1,0);
        //initialization 
       for(int j=1;j<=m;j++)
          prev[j]=prev[j-1]+s2[j-1];
        
        for(int i=1;i<=n;i++){
            cur[0]=prev[0]+s1[i-1];
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                   cur[j]=prev[j-1];
                else
                 cur[j]=min(prev[j]+s1[i-1],cur[j-1]+s2[j-1]);
            }
            prev=cur;
        }
        return prev[m];
    }
};