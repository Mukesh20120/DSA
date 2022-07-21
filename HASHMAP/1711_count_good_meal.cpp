class Solution {
public:
    int countPairs(vector<int>& del) {
        unordered_map<int,int>mp;
        long long ans=0;
        for(int x: del){
            for(int i=1;i<=(1<<21);i*=2){
                if(mp.find(i-x)!=mp.end())
                    ans+=mp[i-x];
            }
            mp[x]++;
        }
        return ans%1000000007;
    }
};