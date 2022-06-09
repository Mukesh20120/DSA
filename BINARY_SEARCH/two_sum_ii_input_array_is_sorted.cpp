//brute force approach solve using unorderd map

class Solution {
public:
    vector<int> twoSum(vector<int>& num, int t) {
        //sum with index;
        int n=num.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
            mp[num[i]]=i;
      vector<int>ans(2);
        for(int i=0;i<n;i++){
            int temp=t-num[i];
            if(mp.find(temp)!=mp.end()){
                ans[0]=i+1;
                ans[1]=mp[temp]+1;
                break;
            }
        }
        if(ans[0]>ans[1])
            swap(ans[0],ans[1]);
        
        return ans;
    }
};

//optimal solution using binary serach

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        int i=0;
        int j=nums.size()-1;
        vector<int>ans(2);
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum==t){
                ans[0]=i+1;
                ans[1]=j+1;
                break;
            }
            else if(sum>t)
                j--;
            else
                i++;
        }
        return ans;
    }
};