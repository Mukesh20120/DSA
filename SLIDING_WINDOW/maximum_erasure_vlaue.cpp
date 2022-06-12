//using left and right pointer and the hashset to find the unique value


class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       unordered_set<int>map;
        int n=nums.size();
        int sum=0,maxi=-1,r=0;
        for(int i=0;i<n;i++){
            while(map.find(nums[i])!=map.end()){
                map.erase(nums[r]);
                sum-=nums[r];
                r++;
            }
            sum+=nums[i];
            map.insert(nums[i]);
            maxi=max(sum,maxi);
        }
        return maxi;
    }
};


class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<bool>hash(10001,false);
        int i,j,sum,maxi;
        i=j=sum=maxi=0;
        int n=nums.size();
        while(j<n){
            sum+=nums[j];
            if(hash[nums[j]]==true){
            while(i<j && nums[i]!=nums[j]){
                sum-=nums[i];
                hash[nums[i]]=false;
                i++;
            }
            sum-=nums[i];
                hash[nums[i]]=false;
                i++;
            }
            hash[nums[j]]=true;
            maxi=max(sum,maxi);
            j++;
        }
        return maxi;
    }
};