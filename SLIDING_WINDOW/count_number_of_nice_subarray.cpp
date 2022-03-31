class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
    int atmost(vector<int>&nums,int k){
        int n=nums.size();
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1)
                k--;
            while(k<0){
                if(nums[j]%2==1)
                    k++;
                j++;
            }
          ans+=i-j+1;  
        }
        return ans;
    }
};