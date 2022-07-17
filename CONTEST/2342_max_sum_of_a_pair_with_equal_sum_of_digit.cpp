class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>ds;
        for(int i=0;i<n;i++){
            int sum=0;
            int n=nums[i];
            while(n){
                sum+=n%10;
                n/=10;
            }
           ds.push_back({sum,nums[i]});
        }
        
       sort(ds.rbegin(),ds.rend());
        int ans=INT_MIN;
        for(int i=1;i<ds.size();i++){
           if(ds[i].first==ds[i-1].first)
               ans=max(ans,ds[i].second+ds[i-1].second);
        }
        return ans==INT_MIN?-1:ans;
    }
};