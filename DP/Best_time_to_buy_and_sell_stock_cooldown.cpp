//naive recursion approach little bit modified of best time to buy and sell 2

class Solution {
public:
    int helper(vector<int>&prices,int i,bool flag,int n){
        //base case
        if(i>=n)return 0;
        //we have two option here to either buy or sell it depend on previous choices
        if(flag){
            //here two option either buy cur one or move to next without buy
            return max(-prices[i]+helper(prices,i+1,false,n),helper(prices,i+1,true,n));
        }
        //here also two option either sell here or move on next element to sell
        return max(prices[i]+helper(prices,i+2,true,n),helper(prices,i+1,false,n));
    }
    int maxProfit(vector<int>& prices) {
        //same as buy and sell stock 2 question 
        //      vector,index,flag to check weather buy or sell,size
        return helper(prices,0,true,prices.size());
    }
};

//memoization above code 
class Solution {
    private:
    int dp[5001][2];
public:
    int helper(vector<int>&prices,int i,bool flag,int n){
        //base case
        if(i>=n)return 0;
        if(dp[i][flag]!=-1)return dp[i][flag];
        //we have two option here to either buy or sell it depend on previous choices
        if(flag){
            //here two option either buy cur one or move to next without buy
            return dp[i][flag]=max(-prices[i]+helper(prices,i+1,false,n),helper(prices,i+1,true,n));
        }
        //here also two option either sell here or move on next element to sell
        return dp[i][flag]=max(prices[i]+helper(prices,i+2,true,n),helper(prices,i+1,false,n));
    }
    int maxProfit(vector<int>& prices) {
        //same as buy and sell stock 2 question 
        //      vector,index,flag to check weather buy or sell,size
        memset(dp,-1,sizeof(dp));
        return helper(prices,0,true,prices.size());
    }
};

//optimal solution
class Solution {
public:
       
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int flag=0;flag<=1;flag++){
              if(flag)
             dp[i][flag]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
              else
            dp[i][flag]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
            }
        }
        return dp[0][1];
    }
};