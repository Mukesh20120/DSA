//brute force approach
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //brute force approach is search for linear search
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target)
                return i;
        }
        return -1;
    }
};