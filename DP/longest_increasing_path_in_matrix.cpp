//recursion solution 

class Solution {
    int n,m;
    int di[4]={-1,0,1,0};
    int dj[4]={0,1,0,-1};
public:
    int helper(vector<vector<int>>&matrix,int i,int j,int prev){
        //boundary cases
        if(i>=n || i<0 || j>=m || j<0 || matrix[i][j]<=prev)
            return 0;
        int ans=0;
        for(int ind=0;ind<4;ind++){
            ans=max(ans,1+helper(matrix,i+di[ind],j+dj[ind],matrix[i][j]));
        }
        return ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        int res=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res=max(res,helper(matrix,i,j,-1));
            }
        }
        return res;
    }
};


//memoization above code 

class Solution {
    int dp[201][201];
    int n,m;
    int di[4]={-1,0,1,0};
    int dj[4]={0,1,0,-1};
public:
    int helper(vector<vector<int>>&matrix,int i,int j,int prev){
        //boundary cases
        if(i>=n || i<0 || j>=m || j<0 || matrix[i][j]<=prev)
            return 0;
        if(dp[i][j])
            return dp[i][j];
        int ans=0;
        for(int ind=0;ind<4;ind++){
            ans=max(ans,1+helper(matrix,i+di[ind],j+dj[ind],matrix[i][j]));
        }
        return dp[i][j]=ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        int res=1;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res=max(res,helper(matrix,i,j,-1));
            }
        }
        return res;
    }
};