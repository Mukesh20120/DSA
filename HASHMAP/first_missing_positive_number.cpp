class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //using extra space unordered map
        int lar=0;
        unordered_map<long long,bool>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=true;
            if(lar<nums[i])
                lar=nums[i];
        }
        int i;
        for(i=1;i<=lar;i++){
            if(mp.find(i)==mp.end())
                return i;
        }
        return i;
    }
};