class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
     int maxvalue=0;
        int s=0,e=0;
        int zero=0;
        for(e=0;e<nums.size();e++){
            if(nums[e]==0)
                zero++;
            while(zero>k){
                if(nums[s]==0)
                    zero--;
                s++;
            }
            maxvalue=max(maxvalue,e-s+1);
        }
        return maxvalue;
    }
};