class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0,k=0,n=nums.size(),ans=0;
        for(i=0;i<n;i++){
            if(nums[i]==0)
               k++;
            while(k>1){
                if(nums[j]==0)
                    k--;
                j++;
            }
         // cout<<i<<" "<<j<<" "<<k<<endl;
            ans=max(ans,i-j);
        }
        return ans;
    }
};