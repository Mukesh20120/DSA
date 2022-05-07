//recursion + memoization 

class Solution {
public:
   static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
      bool checkword(string& prev, string& curr) {
        int m = prev.length();
        int n = curr.length();
        
        if(n-m != 1 || m >= n)
            return false;
        
        int i = 0, j = 0;
		//prev should be a subsequence of curr
        while(i < m && j < n) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i==m;
    }
    
    int lis(vector<string>&words,int cur,int prev,vector<vector<int>>&dp){
        //base case 
        if(cur==words.size())
            return 0;
        if(dp[cur][prev+1]!=-1)
            return dp[cur][prev+1];
        //we have two option not take and then take
       int take=0;
        if(prev<0 || checkword(words[prev],words[cur]))
            take=1+lis(words,cur+1,cur,dp);
        
     int nottake=lis(words,cur+1,prev,dp);
        
        return dp[cur][prev+1]=max(take,nottake);
    }
    
    int longestStrChain(vector<string>& words) {
        //first we have to sort the given vector of string from its size
        sort(words.begin(),words.end(),comp);
        //passing vector,current index and previous
        int n=words.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
      return lis(words,0,-1,dp);
    }
};

//optimal solution using dp upto down

class Solution {
public:
   static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
      bool checkword(string& prev, string& curr) {
        int m = prev.length();
        int n = curr.length();
        
        if(n-m != 1 || m >= n)
            return false;
        
        int i = 0, j = 0;
		//prev should be a subsequence of curr
        while(i < m && j < n) {
            if(prev[i] == curr[j]) {
                i++;
            }
            j++;
        }
        return i==m;
    }
    
    int modifiedlis(vector<string>&words){
      int n=words.size();
        vector<int>dp(n,1);
        int result=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(checkword(words[j],words[i])){
                    dp[i]=max(dp[i],1+dp[j]);
                    result=max(result,dp[i]);
                }
            }
        }
        return result;
    }
    
    int longestStrChain(vector<string>& words) {
        //first we have to sort the given vector of string from its size
        sort(words.begin(),words.end(),comp);
       
      return modifiedlis(words);
    }
};