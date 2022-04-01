class Solution {
public:
    int totalFruit(vector<int>& f) {
        unordered_map<int,int>mp;
        int i=0,j=0,ans=0;
        for(;j<f.size();j++){
            mp[f[j]]++;
            while(mp.size()>2){
                if(mp[f[i]]==1)
                    mp.erase(f[i]);
                else
                    mp[f[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};