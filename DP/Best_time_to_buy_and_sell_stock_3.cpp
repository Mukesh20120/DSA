//recursion solution modification in buy and sell stock 2 
//same pattern question
class Solution {
public:
    int helper(int n,vector<int>nums,int buy,int count,int i){
        //base case
        if(i==n)return 0;
        //we have complete the two transaction
        if(count==0)return 0;
        //we have two choices either buy or sell  the choice depend on previous choice as shown by buy
        int profit=0;
       if(buy){
           //we have two option here either we buy or not buy
           //the transction is not complete until we not sell the stock
           profit=max(-nums[i]+helper(n,nums,0,count,i+1),helper(n,nums,1,count,i+1));
       }
        else{
            //similar have two condition either sell or not
            //if we sell here then the tranction is complete count-- if not then count remain as it is
            profit=max(nums[i]+helper(n,nums,1,count-1,i+1),helper(n,nums,0,count,i+1));
        }
      return profit;
    }
    
    int maxProfit(vector<int>& prices) {
        //similar as best time to buy and sell ii just we have to make variable to count the no of trancation done
        //we are sending n,vector,buy/sell,count transaction
        return helper(prices.size(),prices,1,2,0);
    }
};

//using memoization as we know the index,buy/not,count of transaction is changing
//then we made 3d dp but code giving MLE memory limit exceed
class Solution {
    private:
    int dp[100002][2][3];
public:
    int helper(int n,vector<int>&nums,int buy,int count,int i){
        //base case
        if(i==n)return 0;
        //we have complete the two transaction
        if(count==0)return 0;
        //we have two choices either buy or sell  the choice depend on previous choice as shown by buy
        if(dp[i][buy][count]!=-1)return dp[i][buy][count];
        int profit=0;
       if(buy){
           //we have two option here either we buy or not buy
           //the transction is not complete until we not sell the stock
           dp[i][buy][count]=max(-nums[i]+helper(n,nums,0,count,i+1),helper(n,nums,1,count,i+1));
       }
        else{
            //similar have two condition either sell or not
            //if we sell here then the tranction is complete count-- if not then count remain as it is
            dp[i][buy][count]=max(nums[i]+helper(n,nums,1,count-1,i+1),helper(n,nums,0,count,i+1));
        }
      return dp[i][buy][count];
    }
    
    int maxProfit(vector<int>& prices) {
        //similar as best time to buy and sell ii just we have to make variable to count the no of trancation done
        //we are sending n,vector,buy/sell,count transaction
        memset(dp,-1,sizeof(dp));
        return helper(prices.size(),prices,1,2,0);
    }
};
//tabular form same as previous concept
class Solution {
    private:
    int dp[100002][2][3];
public:
    int helper(int n,vector<int>&nums,int buy,int count,int i){
        if(i==n)return 0;
        if(count==0)return 0;
        if(dp[i][buy][count]!=-1)return dp[i][buy][count];
        int profit=0;
     
      return dp[i][buy][count];
    }
    
    int maxProfit(vector<int>& prices) {
        //make a 3d vector
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        //as we initilized every thing with 0 we dont need to initilized it again or care about it
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int count=1;count<=2;count++){
                  if(buy){
                 dp[i][buy][count]=max(-prices[i]+dp[i+1][0][count],dp[i+1][1][count]);
                      }
                 else{
             dp[i][buy][count]=max(prices[i]+dp[i+1][1][count-1],dp[i+1][0][count]);
                   }    
                }
            }
        }
        return dp[0][1][2];
    }
};

//optimized further using prev and cur modified in above code
class Solution {
    private:
    int dp[100002][2][3];
public:
    int helper(int n,vector<int>&nums,int buy,int count,int i){
        if(i==n)return 0;
        if(count==0)return 0;
        if(dp[i][buy][count]!=-1)return dp[i][buy][count];
        int profit=0;
     
      return dp[i][buy][count];
    }
    
    int maxProfit(vector<int>& prices) {
        //make a 3d vector
        int n=prices.size();
        vector<vector<int>>prev(2,vector<int>(3,0));
        vector<vector<int>>cur(2,vector<int>(3,0));

        //as we initilized every thing with 0 we dont need to initilized it again or care about it
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int count=1;count<=2;count++){
                  if(buy){
                 cur[buy][count]=max(-prices[i]+prev[0][count],prev[1][count]);
                      }
                 else{
             cur[buy][count]=max(prices[i]+prev[1][count-1],prev[0][count]);
                   }    
                }
                prev=cur;
            }
        }
        return prev[1][2];
    }
};



//optimal solution
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int firstbuy=INT_MIN;
        int firstsell=0;
        int secondbuy=INT_MIN;
        int secondsell=0;
        for(int &it: prices){
            firstbuy=max(firstbuy,-it);
            firstsell=max(firstsell,firstbuy+it);
            secondbuy=max(secondbuy,firstsell-it);
            secondsell=max(secondsell,secondbuy+it);
        }
        return secondsell;
    }
};
