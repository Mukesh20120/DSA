#define ll long long
class Solution {
public:
    bool count(vector<int>& nums,ll mid,ll k){
        ll cnt=0;
        for(int &it: nums){
            cnt+=it/mid;
            if(cnt>=k)
                return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        ll low=1,high=0;
        int mx=0;
        for(int &it: candies)
            mx=max(mx,it);
        high=mx;
        int ans=0;
        while(low<=high){
            ll mid=low+(high-low)/2;
            if(count(candies,mid,k)){
                low=mid+1;
                ans=mid;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};