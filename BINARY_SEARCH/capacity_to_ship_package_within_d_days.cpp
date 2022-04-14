class Solution {
public:
    bool helper(int mid,vector<int>&nums,int days){
        int sum=0,count=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>mid){
                count++;
                sum=nums[i];
            }
        }
        if(count<=days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int high=0,low=0;
        //the maximum capacity can take all package in 1 day will be sum of
        //all integer of weight
        // the minimum capacity can tranfer will be each packet in a day
        // it will be the maximum of all the element of weight
        for(int &it: weights){
              high+=it;
           if(low<it)
               low=it;
        }
        //we check for every capacity finding the days
        int result;
        while(low<=high){
            int mid=low+(high-low)/2;//it will be our capacity we check it days required 
            if(helper(mid,weights,days)){
                high=mid-1;
                result=mid;
            }
            else
                low=mid+1;
        }
        return result;
    }
};