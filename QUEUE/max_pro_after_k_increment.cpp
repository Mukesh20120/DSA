class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(int &it: nums)
            q.push(it);
        while(k){
            int t=q.top();
            q.pop();
            t++;
            q.push(t);
            k--;
        }
        long long ans=1;
        int mod=1e9+7;
        while(!q.empty()){
            ans=(ans*q.top()%mod)%mod;
            q.pop();
        }
        return ans;
    }
};