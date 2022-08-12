class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        int mod=1e9+7;
        //we need a map to store the root node and the max it can form
        unordered_map<int,long>mp;
        //first we need to sort the array
        sort(A.begin(),A.end());
        long ans=0;
        int n=A.size();
        //run a loop from 0 to n check for every upto i
        for(int i=0;i<n;i++){
            long count=1;
            for(int j=0;j<i;j++){
                //ex 10 % 2 ==0 and map already have 10/2=5 then means both 2 and 5 are present
                if(A[i]%A[j]==0 && mp.find(A[i]/A[j])!=mp.end()){
                    count+=mp[A[j]]*mp[A[i]/A[j]];
                }
            }
            //after perform all operation on i we insert in map
            mp[A[i]]=count%mod;
            ans+=count;
        }
        ans%=mod;
     
        return (int)ans;
    }
};