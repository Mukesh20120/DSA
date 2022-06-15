class Solution {
public:
    static bool comp(string &a,string &b){
        return a.size()<b.size();
    }
    bool checkpred(string &cur,string &prev){
     int n=cur.size();
     int m=prev.size();
        if(n-m!=1 || m>=n)
            return false;
        int i=0,j=0;
        while(i<m && j<n){
            if(cur[j]==prev[i])
                i++;
            j++;
        }
        return i==m;
    }
    
    
    //here int cur and prev are the index of the words
    int helper(vector<string>&words,int cur,int prev,vector<vector<int>>&dp){
        //base case
        if(cur==words.size())
            return 0;
        if(dp[cur][prev+1]!=-1)
            return dp[cur][prev+1];
        //here we have two cases take or not take
        int take=0;
        //first we check  the prev is greater than 0 or not 
        if(prev<0 || checkpred(words[cur],words[prev]))
            take=1+helper(words,cur+1,cur,dp);
        //other case 
        int nottake=helper(words,cur+1,prev,dp);
        
        return dp[cur][prev+1]=max(take,nottake);
    }
    int helper(vector<string>&words){
        int n=words.size();
        vector<int>dp(n,1);
        int result=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(checkpred(words[i],words[j])){
                    dp[i]=max(dp[i],1+dp[j]);
                    result=max(result,dp[i]);
                }
            }
        }
        return result;
    }
    
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        // int n=words.size();
        // vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        // passing in function
       return helper(words);
     
    }
};