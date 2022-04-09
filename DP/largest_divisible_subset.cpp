class Solution {
public:
    //same as lis of 1d dp modified it with other vector to store 
    //previous index
    vector<int> largestDivisibleSubset(vector<int>& nums) {
                sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        int maxi=0;
        int lastind=0;
        //two loop to modified the dp
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastind=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastind]);
        while(lastind!=hash[lastind]){
            lastind=hash[lastind];
            ans.push_back(nums[lastind]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};