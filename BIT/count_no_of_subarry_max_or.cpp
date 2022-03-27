class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        //step 1 find the max or of nums array
        //as or of 3 and 4 greater mean all value give max 
        int maxi=0;
        for(int it: nums)
            maxi=maxi|it;
        //step 2 question boil down to knapsack find 
        //all the subarray have sum =7
        int a=knapsack(nums,maxi,nums.size()-1,0);
        
        return a;
    }
    int knapsack(vector<int>&nums,int sum,int n,int cur){
        int ans=0;
        if(n<0)
            return 0;
          if(sum==(cur|nums[n]))
             ans=1;
        return ans+knapsack(nums,sum,n-1,cur)+knapsack(nums,sum,n-1,cur|nums[n]);
    }
};

//little bit of changes 
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        //step 1 find the max or of nums array
        //as or of 3 and 4 greater mean all value give max 
        int maxi=0;
        for(int &it: nums)
            maxi=maxi|it;
        //step 2 question boil down to knapsack find 
        //all the subarray have sum =7
        return knapsack(nums,maxi,nums.size()-1,0);
    }
    int knapsack(vector<int>&nums,int sum,int n,int cur){
      //  int ans=0;
        if(n<0)
            return sum==cur;

        return knapsack(nums,sum,n-1,cur)+knapsack(nums,sum,n-1,cur|nums[n]);
    }
};