//recursion approach 
//concept sort the 2d array
// now do longest incresing subsequence

class Solution {
public:
    int helper(vector<vector<int>>&e,int i,int a,int b){
        if(i==e.size())
            return 0;
        int len=0;
        len=helper(e,i+1,a,b);
        if(a<e[i][0] && b<e[i][1]){
            len=max(len,1+helper(e,i+1,e[i][0],e[i][1]));
        }
        return len;
    }
    int maxEnvelopes(vector<vector<int>>& e) {
       sort(e.begin(),e.end());
        return helper(e,0,-1,-1);
    }
};

//optimal solution but it is o(n^2) it gave tle

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin(),e.end());
        int n=e.size();
        vector<int>dp(n,1);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(e[i][0]>e[j][0] && e[i][1]>e[j][1])
                    dp[i]=max(dp[i],dp[j]+1);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};