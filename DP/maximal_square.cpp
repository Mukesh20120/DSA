//brute approach using recursion

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //recursion soltuion
        //to get maximum we need to traverse through each element
        int maxi=0,cur;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    cur=helper(matrix,i,j);
                }
                if(cur>maxi)maxi=cur;
            }
        }
        return maxi*maxi;
    }
    int helper(vector<vector<char>>&matrix,int i,int j){
        //checking base case and boundary case
        if(i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]=='0')
            return 0;
        
        //checking every case we move right down and diagonal
        return 1+min(helper(matrix,i,j+1),min(helper(matrix,i+1,j),helper(matrix,i+1,j+1)));
    }
};


//memoization above code 

class Solution {
    private: int dp[301][301];
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //to get maximum we need to traverse through each element
        if(matrix.size()==0)return 0;
        int maxi=0,cur;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    cur=helper(matrix,i,j);
                }
                if(cur>maxi)maxi=cur;
            }
        }
        return maxi*maxi;
    }
    int helper(vector<vector<char>>&matrix,int i,int j){
        //checking base case and boundary case
        if(i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]=='0')
            return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        //checking every case we move right down and diagonal
        return dp[i][j]=1+min(helper(matrix,i,j+1),min(helper(matrix,i+1,j),helper(matrix,i+1,j+1)));
    }
};

//dp solution 

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //make a dp which will store the previous squares
        //of int size is  +1 greater than given matrix
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              //filling the matrix first also
                if(i==0 || j==0)
                    dp[i][j]=matrix[i][j]=='0'?0:1;
                else
                if(matrix[i][j]=='1'){
                    //then we have to check previous top diagonal left
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                }
                maxi=max(dp[i][j],maxi);
            }
        }
        return maxi*maxi;
    }
};

//more optimal solution of above dp code

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //make a dp which will store the previous squares
        //of int size is  +1 greater than given matrix
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<int>prev(m+1,0),cur(m+1,0);
        
        int maxi=0;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(!i || !j || matrix[i][j]=='0')
                  cur[j]=matrix[i][j]-'0';
              else{
                  cur[j]=1+min(prev[j-1],min(prev[j],cur[j-1]));
              }
                maxi=max(maxi,cur[j]);
            }
            swap(prev,cur);
        }
        return maxi*maxi;
    }
};