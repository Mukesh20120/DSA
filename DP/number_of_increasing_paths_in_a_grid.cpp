//based on increasing path in grid memoization and recursion approach
class Solution {
    int dp[1001][1001];
    int mod=1000000007;
    int n,m;
    int di[4]={-1,0,1,0};
    int dj[4]={0,1,0,-1};
public:
    long long helper(vector<vector<int>>&matrix,int i,int j,int prev){
        //boundary cases
        if(i>=n || i<0 || j>=m || j<0 || matrix[i][j]<=prev)
            return -1;
        if(dp[i][j])
            return dp[i][j];
        long long ans=0;
        for(int ind=0;ind<4;ind++){
            ans+=1+helper(matrix,i+di[ind],j+dj[ind],matrix[i][j]);
        }
        return dp[i][j]=(ans%mod);
    }
    
    int countPaths(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        long long res=0;
       // cout<<n*m;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res+=helper(matrix,i,j,-1);
            }
        }
        res+=(n*m);
       long ans=res%mod;
        return (int)ans;
    }
};