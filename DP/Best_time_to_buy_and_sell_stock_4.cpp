//naive approach using the stock 3 little bit modification recursion

class Solution {
public:
    int helper(vector<int>&prices,int i,int n,int k,int buy,int tra){
        //base case vector is empty or no of tranction is complete
        if(i==n || tra==k)return 0;
        //we have two option depend on our previous choice if we buy then now we sell
        //it we sell previous then we can buy again
        if(buy){
            return max(-prices[i]+helper(prices,i+1,n,k,0,tra),helper(prices,i+1,n,k,1,tra));
        }
        return max(+prices[i]+helper(prices,i+1,n,k,1,tra+1),helper(prices,i+1,n,k,0,tra));
    }
    
    int maxProfit(int k, vector<int>& prices) {
        //we can use same code as in buy and sell stock 3
        //        vector,index,size,transcation,buy/sell
        return helper(prices,0,prices.size(),k,1,0);
    }
};

//same above code memoization accepted
class Solution {
    private:
    int dp[1001][2][101];
public:
    int helper(vector<int>&prices,int i,int n,int k,int buy,int tra){
        //base case vector is empty or no of tranction is complete
        if(i==n || tra==k)return 0;
        if(dp[i][buy][tra]!=-1)return dp[i][buy][tra];
        //we have two option depend on our previous choice if we buy then now we sell
        //it we sell previous then we can buy again
        if(buy){
            return dp[i][buy][tra]=max(-prices[i]+helper(prices,i+1,n,k,0,tra),helper(prices,i+1,n,k,1,tra));
        }
        else
        return dp[i][buy][tra]=max(prices[i]+helper(prices,i+1,n,k,1,tra+1),helper(prices,i+1,n,k,0,tra));
    }
    
    int maxProfit(int k, vector<int>& prices) {
        //we can use same code as in buy and sell stock 3
        //        vector,index,size,transcation,buy/sell
        memset(dp,-1,sizeof(dp));
        return helper(prices,0,prices.size(),k,1,0);
    }
};


//recursion different approach using tansction to calculate total no of transction and 
//it also tell either we have to buy or sell by the value of it
//if it is even mean we have to buy and if it odd we have to sell
//we increase it and when it equal to 2*k we have done our transaction

class Solution {
public:
    int helper(vector<int>&prices,int k,int trans,int i,int n){
        if(i==n || trans==k)return 0;
        //same we have two option either buy or sell depend on our previous choice
        //we maintain transcation to get either buy or sell if even we have to sell odd to buy
        if(trans%2==0){
            return max(-prices[i]+helper(prices,k,trans+1,i+1,n),helper(prices,k,trans,i+1,n));
        }
        return max(prices[i]+helper(prices,k,trans+1,i+1,n),helper(prices,k,trans,i+1,n));
    }
    int maxProfit(int k, vector<int>& prices) {
        //       vector,k,transction,index,size
        return helper(prices,2*k,0,0,prices.size());
    }
};

//memoized above code
class Solution {
    private:
    //as we know the index and the transcation is changing we
    //need 2d dp
    int dp[1001][202];
public:
    int helper(vector<int>&prices,int k,int trans,int i,int n){
        if(i==n || trans==k)return 0;
        if(dp[i][trans]!=-1)return dp[i][trans];
        //same we have two option either buy or sell depend on our previous choice
        //we maintain transcation to get either buy or sell if even we have to sell odd to buy
        if(trans%2==0){
            return dp[i][trans]=max(-prices[i]+helper(prices,k,trans+1,i+1,n),helper(prices,k,trans,i+1,n));
        }
        return dp[i][trans]=max(prices[i]+helper(prices,k,trans+1,i+1,n),helper(prices,k,trans,i+1,n));
    }
    int maxProfit(int k, vector<int>& prices) {
        //       vector,k,transction,index,size
        memset(dp,-1,sizeof(dp));
        return helper(prices,2*k,0,0,prices.size());
    }
};

//tabulation form of above code
class Solution {
  
public:
  
    int maxProfit(int k, vector<int>& prices) {
      //tabular form 2d vector require
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        //as we initilize every thing with 0 we don't need to think about base case
        for(int i=n-1;i>=0;i--){
            for(int trans=2*k-1;trans>=0;trans--){
              if(trans%2==0)
             dp[i][trans]=max(-prices[i]+dp[i+1][trans+1],dp[i+1][trans]);
            else
             dp[i][trans]=max(prices[i]+dp[i+1][trans+1],dp[i+1][trans]);
            }
        }
        return dp[0][0];
    }
};

//further optimization
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
      //tabular form 2d vector require
        int n=prices.size();
        vector<int>prev(2*k+1,0);
         vector<int>cur(2*k+1,0);
        //as we initilize every thing with 0 we don't need to think about base case
        for(int i=n-1;i>=0;i--){
            for(int trans=2*k-1;trans>=0;trans--){
              if(trans%2==0)
             cur[trans]=max(-prices[i]+prev[trans+1],prev[trans]);
            else
             cur[trans]=max(prices[i]+prev[trans+1],prev[trans]);
            }
            swap(prev,cur);
        }
        return prev[0];
    }
};