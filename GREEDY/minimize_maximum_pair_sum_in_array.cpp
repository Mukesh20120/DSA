//brute approach
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,n=nums.size();
        
        for(int i=0;i<n;i++)
            ans=max(ans,nums[i]+nums[n-i-1]);
        
        return ans;
    }
};

//optimal approach
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        //making a array
        int arr[100001]={0};
        //filling it frequency with element it index
        for(int &i: nums)
            arr[i]++;
        //size/2,left,right pointer ,store ans in variable
        int size=nums.size()/2,l=1,r=100000,ans=0;
        while(size){
            if(!arr[l]){
                l++;
                continue;
            }
            if(!arr[r]){
                r--;
                continue;
            }
            ans=max(ans,l+r);
            //decreasing the frequency 
            arr[l]--;arr[r]--;size--;
        }
        return ans;
    }
};