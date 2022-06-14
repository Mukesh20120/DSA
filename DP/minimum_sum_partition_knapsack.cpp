class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	  int sum=0;//total sum
	  for(int i=0;i<n;i++)
	      sum+=arr[i];
	  int half=sum/2;
	  
	  bool dp[n+1][half+1];
	  //initilization
	  for(int j=0;j<=half;j++)
	     dp[0][j]=false;
	  for(int i=0;i<=n;i++)
	     dp[i][0]=true;
	  
	  for(int i=1;i<=n;i++){
	      for(int j=1;j<=half;j++){
	          if(arr[i-1]>j)
	          dp[i][j]=dp[i-1][j];
	          else
	          dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
	      }
	  }
	  
	  //checking from back
	  int sechalf;
	  for(sechalf=half;sechalf>=0;sechalf--)
	     if(dp[n][sechalf])
	        break;
	  
	  
	 return sum-(2*sechalf);
	}

};