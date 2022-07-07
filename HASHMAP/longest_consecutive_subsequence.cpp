class Solution {
public:
    bool check(vector<int>&nums,int x){
        for(int i=0;i<nums.size();i++)
            if(nums[i]==x)
                return true;
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        //we take an element from nums and search for consecutive
        int ans=0;
        for(int &num: nums){
            int t=1;
            int cur=num;
            while(check(nums,cur+1)){
                t++;
                cur++;
            }
            ans=max(t,ans);
        }
        return ans;
    }
};


//other approach sort the array and count the consecutive
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        int cur=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1] && nums[i]==nums[i-1]+1)
                cur++;
            else{
                ans=max(cur,ans);
                cur=1;
            }
        }
        return max(ans,cur);
    }
};

//using hash set function applied in brute force approach
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //modification in brute force approach using set
        set<int>hash;
        int ans=0;
        for(int &i: nums)
            hash.insert(i);
        //now same as brute force
        for(int &it: nums){
            if(!hash.count(it-1)){
                int curstrk=1;
                int cur=it;
                while(hash.count(cur+1)){
                    cur++;
                    curstrk++;
                }
                ans=max(curstrk,ans);
            }
        }
        return ans;
    }
};