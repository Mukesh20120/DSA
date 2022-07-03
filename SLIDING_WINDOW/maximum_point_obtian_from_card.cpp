//brute force approach using dynamic programming but giving mle for long case+ memoization
class Solution {
public:
    int helper(vector<int>&cp,int b,int e,int k,vector<vector<int>>&dp){
        if(k==0)return 0;
        if(b>e)return 0;
        
        if(dp[b][e]!=-1)return dp[b][e];
        //in first case we take from beginning 
        int start=helper(cp,b+1,e,k-1,dp)+cp[b];
        int end=helper(cp,b,e-1,k-1,dp)+cp[e];
        
        return dp[b][e]=max(start,end);
    }
    int maxScore(vector<int>& cp, int k) {
        //brute force approach using recursion
        vector<vector<int>>dp(cp.size()+1,vector<int>(cp.size()+1,-1));
        return helper(cp,0,cp.size()-1,k,dp);
    }
};

//sliding window approach
//we need to find the subarray of totalsize-k if we remove the subarray we get max result

class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
       //we just need to find minimum sub array of length 
        //size of vector -k
        int n=cp.size();
        int sw=n-k;
        int sum=0;
        int ans=0;
      for(int i=0;i<n;i++){
          if(i<sw){
                 sum+=cp[i];
              ans=sum;
          }  
          else{
              sum=sum+cp[i]-cp[i-sw];
              ans=min(ans,sum);
          }
      }
        int total=accumulate(cp.begin(),cp.end(),0);
        
        return total-ans;
        
    }
};

//same code just arrange the syntac of the above code
class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n=cp.size();
        int w=n-k;
        int ans=0,sum=0;
        for(int i=0;i<w;i++)
            sum+=cp[i];
        ans=sum;
        for(int i=w;i<n;i++){
            sum+=cp[i]-cp[i-w];
            ans=min(ans,sum);
        }
        return accumulate(cp.begin(),cp.end(),0)-ans;
    }
};