//recursion + memoization approach
int dp[1003][1003];

int knapsack(vector<int>&a,vector<int>&b,int sum,int n){
    if(n==0 || sum==0)
    return 0;
    if(dp[sum][n]!=-1)
    return dp[sum][n];
    if(b[n-1]>sum)
    return dp[sum][n]=knapsack(a,b,sum,n-1);
    
    return dp[sum][n]=max(knapsack(a,b,sum-b[n-1],n-1)+a[n-1],knapsack(a,b,sum,n-1));
}

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n=A.size();
    memset(dp,-1,sizeof(dp));
    return knapsack(A,B,C,n);
}

//optimized version of above code

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    //uptodown approach
    int n=A.size();
    int dp[n+1][C+1];
    //initilization of the array
    //same as recursion if n and sum ==0 then return 0
    for(int i=0;i<=n;i++){
        for(int j=0;j<=C;j++){
            if(i==0 || j==0)
             dp[i][j]=0;
        }
    }
    //here our weight is j
    for(int i=1;i<=n;i++){
        for(int j=1;j<=C;j++){
            if(B[i-1]<=j)
           dp[i][j]=max(dp[i-1][j-B[i-1]]+A[i-1],dp[i-1][j]);
            else
              dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][C];
}
//more optimized version of above code using 1D dp

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    //uptodown approach
    int n=A.size();
    vector<int>prev(C+1,0),cur(C+1);
    //here our weight is j
    for(int i=1;i<=n;i++){
        prev[0]=0;
        for(int j=1;j<=C;j++){
            if(B[i-1]<=j)
           cur[j]=max(prev[j-B[i-1]]+A[i-1],prev[j]);
            else
              cur[j]=prev[j];
        }
        prev=cur;
    }
    return prev[C];
}



//more optimal solution on interview bit 

int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n=A.size();
    int dp[C+1]={};
    for(int i=0;i<n;i++)
    for(int j=C;j>=B[i];j--)
      dp[j]=max(dp[j],dp[j-B[i]]+A[i]);
return dp[C];
}

