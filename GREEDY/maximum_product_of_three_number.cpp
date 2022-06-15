class Solution {
public:
    int maximumProduct(vector<int>& nums) {
     int max1,max2,max3,min1,min2;
        min1=min2=1001;
        max1=max2=max3=-1001;
        for(int i=0;i<nums.size();i++){
            if(max1<nums[i]){
               max3=max2;
                max2=max1;
               max1=nums[i];
            }
            else if(max2<nums[i]){
                max3=max2;
                max2=nums[i];
            }
            else if(max3<nums[i])
                max3=nums[i];
            
           if(min1>nums[i]){
                min2=min1;
                min1=nums[i];
            }
            else if(min2>nums[i])
                min2=nums[i];
        }
    return max(max1*max2*max3,min1*min2*max1);
    }
};