//recursion + memoization
#define INT_MAX 100000000
class Solution {
    int dp[101][101][21];
public:
    int helper(vector<int>&h,vector<vector<int>>&c,int t,int ncnt,int i,int prev){
        //base case we are at the end of the house index
        //we need to check the neighbourhood cnt equal to target or not
        if(i==h.size())
            return ncnt==t?0:INT_MAX;
        if(ncnt>t)
            return INT_MAX;
        
        if(dp[ncnt][i][prev]!=-1)return dp[ncnt][i][prev];
        
        int mincost=INT_MAX;
        //now we have two case one house already color or not color
        if(h[i]){
            int newncnt=ncnt+(h[i]!=prev);
            mincost=helper(h,c,t,newncnt,i+1,h[i]);
        }
        else{
            for(int j=1;j<=c[0].size();j++){
                int newncnt=ncnt+(j!=prev);
                int curcost=c[i][j-1]+helper(h,c,t,newncnt,i+1,j);
                mincost=min(mincost,curcost);
            }
        }
        return dp[ncnt][i][prev]=mincost;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        //passing target,neibhourcnt,index,prevcolor
        memset(dp,-1,sizeof(dp));
       int ans=helper(houses,cost,target,0,0,0);
        return ans==INT_MAX?-1:ans;
    }
};