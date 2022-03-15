class Solution {
public:
    int fun(string s,string t,int i,int j){
        
        if(i<0)return j+1;
        if(j<0)return i+1;
        //choice we have condition when all the character are equal
        if(s[i]==t[j]) //when the character match then we required 0 operation
            return 0+fun(s,t,i-1,j-1); 
        //now we have three condition insertion,deletion,replace
        int a=fun(s,t,i-1,j);//deletion we delete char now move ahead to check next
        int b=fun(s,t,i,j-1);//insertion new element added and j move ahead
        int c=fun(s,t,i-1,j-1);//we replace the char then we move both ahead
        
        //we take which one give minimum value
        return  1+min(a,min(b,c));
    }
    
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        return fun(word1,word2,n-1,m-1);
    }
};
//2 method 
//above can be memoized

//3 method tabular method 

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        
        //vector for dp for tabular form
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        //initilization of base case same as recursion
        for(int i=0;i<=n;i++)
            dp[i][0]=i;
        for(int j=0;j<=m;j++) 
            dp[0][j]=j;
        
        //travesing 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //condition is same as in recursion 
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=0+dp[i-1][j-1];
                else
                    dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            }
        }    
        return dp[n][m];
    }
};

//4 mrthod tabular making 1D dp

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        
        //vector for dp for tabular form
        vector<int>prev(m+1,0),cur(m+1,0); //size will be m b/c we replace row from two vector
        
        //initilization of base case same as recursion
      
      
        for(int j=0;j<=m;j++) 
            prev[j]=j;
        
        //travesing 
        for(int i=1;i<=n;i++){
            cur[0]=i;
            for(int j=1;j<=m;j++){
                //condition is same as in recursion 
                if(word1[i-1]==word2[j-1])
                    cur[j]=0+prev[j-1];
                else
                    cur[j]=1+min(prev[j],min(prev[j-1],cur[j-1]));
            }
            prev=cur;
        }    
        return prev[m];
    }
};
//to get up to this solution we started from recursion taking reference of
//previous one solution