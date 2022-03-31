//fist method using unordered map
//we are changing odd as 1 and even as 0 the question boil down to find the 
//sub array who sum equal to k
//TC=O(n) ans SC O(n) as we are using map
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int sum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            sum+=nums[i]&1;
            if(sum==k)
                cnt++;
            if(mp.find(sum-k)!=mp.end())
                cnt+=mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};

//TC O(n) SC(1)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
    int atmost(vector<int>&nums,int k){
        int n=nums.size();
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1)
                k--;
            while(k<0){
                if(nums[j]%2==1)
                    k++;
                j++;
            }
          ans+=i-j+1;  
        }
        return ans;
    }
};