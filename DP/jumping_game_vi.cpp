//recursion approach

class Solution {
public:
    int helper(vector<int>&nums,int k,int i){
        if(i>=nums.size())return 0;
        
        int ans=INT_MIN;
        
        for(int j=1;j<=k;j++){
           
            ans=max(ans,helper(nums,k,i+j)+nums[i]);
        }
        
        return ans;
    }
    
    int maxResult(vector<int>& nums, int k) {
        int ans=helper(nums,k,0);
        return ans;
    }
};


//solve using priority queue 

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        pq.push({nums[0],0});
        int sum=nums[0];
        for(int i=1;i<nums.size();i++){
            while(!(i-pq.top().second<=k))
                pq.pop();
            sum=pq.top().first+nums[i];
            pq.push({sum,i});
        }
        return sum;
    }
};


//using vector to store the value 
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[n-1]=nums[n-1];
        int bestval=nums[n-1];
        int bestind=n-1;
        for(int i=n-2;i>=0;i--){
            if(bestind<i+k)
                dp[i]=nums[i]+bestval;
            else{
                int newbest=INT_MIN;
                for(int j=1;j<=k;j++){
                    int t=min(i+j,n-1);
                    if(newbest<dp[t]){
                        newbest=dp[t];
                        bestind=t;
                    }
                    bestval=newbest;
                    dp[i]=nums[i]+bestval;
                }
            }
            if(dp[i]>=bestval){
                bestval=dp[i];
                bestind=i;
            }
        }
        return dp[0];
    }
};
