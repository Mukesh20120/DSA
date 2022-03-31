class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //same as previous done by using unordere map
         //   store sum and its frequency
        unordered_map<int,int>mp;
        int n=nums.size(),ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i]; //increasing the sum
            if(sum==goal)  //if sum==goal
                ans++;  
             //finding if the sum-goal is present in map
            if(mp.find(sum-goal)!=mp.end())
                ans+=mp[sum-goal];
            
            mp[sum]++;
        }
        return ans;
    }
};

//optimal solution
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int s) {
        return atmost(nums,s)-atmost(nums,s-1);
    }
    int atmost(vector<int>&nums,int k){
        if(k<0)
            return 0;
        int j=0,ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            k-=nums[i];
            while(k<0){
                k+=nums[j++];
            }
            ans+=i-j+1;
        }
        return ans;
    }
};