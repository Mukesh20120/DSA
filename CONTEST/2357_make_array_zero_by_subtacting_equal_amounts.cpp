class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        //let do with brute force approach
        sort(nums.begin(),nums.end());
        int i=0,n=nums.size();
        int ans=0;
        while(i<n){
            if(nums[i]!=0){
                for(int j=i+1;j<n;j++){
                    nums[j]=nums[j]-nums[i];
                }
                ans++;
            }
            i++;
        }
        return ans;
    }
};


//optimal solution using unordered set
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
     unordered_set<int>s=unordered_set(nums.begin(),nums.end());
        return s.size()-s.count(0);
    }
};