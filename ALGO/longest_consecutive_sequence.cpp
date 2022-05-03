//passing most 69 testcase out of 70
//giving TLE
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //brute approach using two loop
        sort(nums.begin(),nums.end());
        int count,temp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            count=1;
            temp=nums[i];
            for(int j=i;j<nums.size();j++){
               if(nums[j]==temp+1){
                   temp++;
                   count++;
               } 
            }
            ans=max(ans,count);
        }
        return ans;
    }
};


//optimized above code solve using sorting the array 
//time complexity nlogn

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //brute approach using two loop
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int count=1;
        int ans=1;
        for(int i=1;i<nums.size();i++){
           if(nums[i]!=nums[i-1]){
               if(nums[i]==nums[i-1]+1)
                   count++;
               else{
                   ans=max(ans,count);
                   count=1;
               }
           }
        }
        return max(ans,count);
    }
};