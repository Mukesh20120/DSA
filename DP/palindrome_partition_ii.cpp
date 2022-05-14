//solve using recursion

class Solution {
public:
    int minCut(string s) {
        //we can solve this problem using recursion
        int n=s.length(); //length of the string
        
        //calling function reducing -1 b/c in the end of the string it make another partition ex aab make partition at end of b also
       return fun(s,0,n)-1;
    }
    int fun(string &s,int i,int n){
        //base case if 
        if(i==n)
            return 0;
        //store the ans
       int mincost=INT_MAX;
        //checking all possible palindrome and then passing the remain string for check
        for(int j=i;j<n;j++){
            if(checkpalindrome(i,j,s)){
                int cost=1+fun(s,j+1,n);
                mincost=min(cost,mincost);
            }
        }
        return mincost;
    }
    //palindrome function
    bool checkpalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};


//memoization above code
class Solution {
public:
    int minCut(string s) {
        //we can solve this problem using recursion
        int n=s.length(); //length of the string
        
        //calling function reducing -1 b/c in the end of the string it make another partition ex aab make partition at end of b also
        vector<int>dp(n,-1);
       return fun(s,0,n,dp)-1;
    }
    int fun(string &s,int i,int n,vector<int>&dp){
        //base case if 
        if(i==n)
            return 0;
        if(dp[i]!=-1)return dp[i];
        //store the ans
       int mincost=INT_MAX;
        //checking all possible palindrome and then passing the remain string for check
        for(int j=i;j<n;j++){
            if(checkpalindrome(i,j,s)){
                int cost=1+fun(s,j+1,n,dp);
                mincost=min(cost,mincost);
            }
        }
        return dp[i]=mincost;
    }
    //palindrome function
    bool checkpalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};


//optimal solution using tabular dp
class Solution {
public:
    int minCut(string s) {
        int n=s.length(); 
        //making and initialzation of dp vector with 0
        vector<int>dp(n+1,0);
        //base case
        dp[n]=0;
            //we run a loop from n-1 to 0
        for(int i=n-1;i>=0;i--){
            int mincost=INT_MAX;
         //checking all possible palindrome and then passing the remain string for check
         for(int j=i;j<n;j++){
            if(checkpalindrome(i,j,s)){
                int cost=1+dp[j+1];
                mincost=min(cost,mincost);
            }
           }
            dp[i]=mincost;
          }
       return dp[0]-1;
    }
   
    //palindrome function
    bool checkpalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};