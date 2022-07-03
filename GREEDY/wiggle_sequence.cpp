//recursion approach
class Solution {
public:
    int calculate(vector<int>&nums,int i,bool pick){
        int mc=0;
        for(int j=i+1;j<nums.size();j++){
         //two condition pick then no shoud positve or pick false number should negative
            if((pick && nums[i]<nums[j]) || (!pick && nums[i]>nums[j]))
                mc=max(mc,calculate(nums,j,!pick)+1);
        }
        return mc;
    }
    int wiggleMaxLength(vector<int>& nums) {
        //brute force using recursion
        if(nums.size()<2)
            return nums.size();
        return 1+max(calculate(nums,0,true),calculate(nums,0,false));
    }
};


//optimal approach solve own my own
//just we have to cnt up and down if there is more up move ahead skip it

class Solution {
public:
    int helper(vector<int>&nums,bool updown){
        int ans=1;
        for(int i=1;i<nums.size();i++){
            if(updown && nums[i]>nums[i-1]){
                ans++;
                updown=false;
            }
            else if(!updown && nums[i]<nums[i-1]){
                ans++;
                updown=true;
            }
        }
        return ans;
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        return max(helper(nums,false),helper(nums,true));
    }
};