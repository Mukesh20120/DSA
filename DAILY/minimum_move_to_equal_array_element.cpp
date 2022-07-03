class Solution {
public:
    int minMoves2(vector<int>& nums) {
       sort(nums.begin(),nums.end());
        int n=nums.size();
        int res=0;
        for(int i=0;i<n/2;i++)
            res+=nums[n-i-1]-nums[i];
        return res;
    }
};