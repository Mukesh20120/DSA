class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int cnt=0;
        int i=0,n=nums.size(),j=n-1;
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum==k)
               cnt++,j--,i++;
            else if(sum>k)
                j--;
            else
                i++;
        }
        return cnt;
    }
};