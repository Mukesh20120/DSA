class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0)
                sum=0;
         
          ans=max(sum,ans);
        }
        return ans;
    }
};