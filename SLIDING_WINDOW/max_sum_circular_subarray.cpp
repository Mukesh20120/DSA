class Solution {
public:
    //codebix yt
    
    //the problem with this code is we are modifing the given vector
    int maxSubarraySumCircular(vector<int>& nums) {
        //question break down into two parts firs max from subarry and max from circular
        int b=kadane(nums); //first we findin the max subarray
        int a=circular(nums);
        if(a==0)
            return b;
    
        return max(a,b);
    }
    int circular(vector<int>&nums){
        int totalsum=0;
        for(int &it:nums)
            totalsum+=it;
        //changing the sign of all the element of vector
        for(int i=0;i<nums.size();i++)
            nums[i]=-nums[i];
        return totalsum+kadane(nums);
    }
    
    int kadane(vector<int>&nums){
        int sum=0,ans=-40000;
        for(int &it: nums){
            sum+=it;
            if(it>sum)
                sum=it;
            
            if(ans<sum)
                ans=sum;
        }
        return ans;
    }
};