class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long cnt[30]={}; //count the bit and store frequency how many element have same frequency
        long long ans=0; //return answer
        //storing the distinct element in set
        unordered_set<int>A;
        for(int it: nums)
            A.insert(it);
        //storing the bit no to freqency int cnt 
        for(auto it: A){
            int bit=__builtin_popcount(it);
            cnt[bit]++;
        }
        
        for(int i=1;i<30;i++){
            for(int j=1;j<30;j++){
                if(i+j>=k)
                    ans+=cnt[i]*cnt[j];
            }
        }
        return ans;
    }
};