class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        //we will do this with sliding window
        int start=0,end=0,count=0,n=nums.size(),pro=1;
        //we run until end move to last element
        while(end<n){
            pro*=nums[end];
            //now we have two cases
            //if the product is greater then the given value k
            while(start<n && pro>=k){
                pro/=nums[start++];
            }
            //other case if it was smaller
            if(pro<k)
                count+=end-start+1;
            end++;
        }
        return count;
    }
};