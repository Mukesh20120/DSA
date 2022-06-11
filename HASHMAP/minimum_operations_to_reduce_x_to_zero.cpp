//using hashmap 

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        //create unorder map to store the prifix sum and index
        unordered_map<int,int>mp;
        //inset in map with index and until sum<=x
        int sum,res=INT_MAX;
        mp[0]=0;
        //inserting the sum=0 and index=0
        for(int i=0,sum=0;i<nums.size() && sum<=x;++i){
            sum+=nums[i];
            mp[sum]=i+1;
        }
        //checking from last index 
        for(int r=nums.size()-1,sum=0;r>=0 && sum<=x;--r){
            auto it=mp.find(x-sum);
            if(it!=mp.end() && it->second<=r+1){
                res=min(res,(int)nums.size()-r-1+it->second);
            }
            sum+=nums[r];
        }
        return res==INT_MAX?-1:res;
    }
};