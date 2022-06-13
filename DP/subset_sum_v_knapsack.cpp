//recursion approach

int helper(vector<int>&a,int sum,int n){
    //base case we find sum =0 
    if(sum==0)
       return 1;
    //sum is not equal to 0 and we are at the end of array then there
    //is no subset present
    if(n==0)
    return 0;
    
    //we have two cases 1 if element is greater 
    //we don't take the element and find for next element
    if(sum<a[n-1])
      return helper(a,sum,n-1);
    
    //two case take or not take the element
    return (helper(a,sum-a[n-1],n-1) || helper(a,sum,n-1));
}

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    return helper(A,B,n);
}

//memoization of above code 
 int dp[100001][101];

int helper(vector<int>&a,int sum,int n){
    //base case we find sum =0 
    if(sum==0)
       return 1;
    //sum is not equal to 0 and we are at the end of array then there
    //is no subset present
    if(n==0)
    return 0;
    
    if(dp[sum][n]!=-1)
    return dp[sum][n];
    
    //we have two cases 1 if element is greater 
    //we don't take the element and find for next element
    if(sum<a[n-1])
      return dp[sum][n]=helper(a,sum,n-1);
    
    //two case take or not take the element
    return dp[sum][n]=(helper(a,sum-a[n-1],n-1) || helper(a,sum,n-1));
}

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    memset(dp,-1,sizeof(dp));
    return helper(A,B,n);
}

//optimal approach using top to down approach

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    vector<vector<int>>dp(n+1,vector<int>(B+1));
    //initilization
    for(int j=0;j<=B;j++)
        dp[0][j]=0;
    
    for(int i=0;i<=n;i++)
         dp[i][0]=1;
    
   
    //now uptodown approach
    for(int i=1;i<=n;i++){
        for(int j=1;j<=B;j++){
            if(j>=A[i-1])
               dp[i][j]=(dp[i-1][j] || dp[i-1][j-A[i-1]]);
            else
             dp[i][j]=dp[i-1][j];
        }
    }
   return dp[n][B];
}
//space optimization of above code 

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    vector<int>prev(B+1,0),cur(B+1);
    //now uptodown approach
    for(int i=1;i<=n;i++){
         prev[0]=1;
        for(int j=1;j<=B;j++){
            if(j>=A[i-1])
               cur[j]=(prev[j] || prev[j-A[i-1]]);
            else
             cur[j]=prev[j];
        }
        prev=cur;
    }
   return prev[B];
}

//interview bit optimal solution 

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    //trying same as knapsack
   //find the total sum
   int sum=0;
   for(int i=0;i<n;i++)
      sum+=A[i];
      
      if(B>sum)
      return 0;
      
  //making vector for store answer of size equal to total sum
     vector<bool>dp(sum+1,0);
     dp[0]=true; //when 1 value is sum=0 then 
    
//runnig two loop
for(int i=0;i<n;i++){
    for(int j=A[i];j<=sum;j++){
        dp[j]=dp[j]|dp[j-A[i]];
    }
}
     
   return  dp[B];  
}

