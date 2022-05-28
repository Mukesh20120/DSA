class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*(n+1))/2;
        int total=0;
        for(int &it: nums)
            total+=it;
        
        return sum-total;
    }
};