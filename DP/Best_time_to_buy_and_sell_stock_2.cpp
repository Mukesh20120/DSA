//naive approach using recursion and memoization
class Solution {
    private:
    int dp[30001][2];
public:
    int helper(int n,int buy,vector<int>&nums,int i){
        //if we reach the end what we have we return 0
        if(i==n)return 0;
    //now we have two option if previously we buy then we sell only and if previously we sell then we can again buy it for our next profit
     //  int profit=0;
        //if we have to buy 
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
        //we have two option buy or not buy which gave maximum
        dp[i][buy]=max(-nums[i]+helper(n,0,nums,i+1),helper(n,1,nums,i+1));
        }
        else{
        //we sell here or we not sell here
        dp[i][buy]=max(nums[i]+helper(n,1,nums,i+1),helper(n,0,nums,i+1));
        }
        return dp[i][buy];
    }
    int maxProfit(vector<int>& prices) {
                 //  size ,buy or sell,vector,index 
        memset(dp,-1,sizeof(dp));
        return helper(prices.size(),1,prices,0);
    }
};

//modified above code and bottom up dp tabular form

class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
      vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                 if(buy){
               dp[i][buy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
               }
                else{
               dp[i][buy]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
               }
            }
        }
         return dp[0][1];
    }
};

//more optimized the above code prev and cur
class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
      vector<int>prev(2,0),cur(2,0);
        prev[0]=prev[1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                 if(buy){
               cur[buy]=max(-prices[i]+prev[0],prev[1]);
               }
                else{
               cur[buy]=max(prices[i]+prev[1],prev[0]);
               }
            }
            prev=cur;
        }
         return prev[1];
    }
};

//replace the vector with the variables
class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
      //we can replace it with the variable also
    // let assume prev[1]=buy and prev[0]=notbuy
    //same as cur curnotbuy and buy 
        int prevnotbuy,prevbuy,curnotbuy,curbuy;
        prevnotbuy=prevbuy=0;
        for(int i=n-1;i>=0;i--){
               curbuy=max(-prices[i]+prevnotbuy,prevbuy);
               curnotbuy=max(prices[i]+prevbuy,prevnotbuy);
          prevbuy=curbuy;
        prevnotbuy=curnotbuy;
        }
         return prevbuy;
    }
};


