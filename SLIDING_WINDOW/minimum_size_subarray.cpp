class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        int temp=0;
        int j=0;
        for(int i=0;i<n;i++){
            temp+=nums[i];  
            while(temp>=tar){
                ans=min(i-j+1,ans);
                temp-=nums[j];
                j++;
            }
        }
        if(ans==INT_MAX)
            return 0;
        
        return ans;
    }
};