class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn=nums[0];
        int sum=0;
        for(int &i: nums){
            mn=min(mn,i);
            sum+=i;
        }
        return sum-(mn*nums.size());
    }
};