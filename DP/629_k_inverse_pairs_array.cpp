//recursion+memorization but give tle
class Solution {
    private:
    int dp[1001][1001];
public:
    int kInversePairs(int n, int k) {
        if(n==0)
            return 0;
        if(k==0)
            return 1;
        if(dp[n][k])
            return dp[n][k];
        int inv=0;
        for(int i=0;i<=min(k,n-1);i++)
            inv=(inv+kInversePairs(n-1,k-i))%1000000007;
        dp[n][k]=inv;
        return dp[n][k];
    }
};