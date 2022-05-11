class Solution {
//brute force approach using recursion    


public:
    int countVowelStrings(int n) {
       int count=0;
       counting(n,-1,count);   
        return count;
    }
    void counting(int n,int prev_char,int &count){
        if(n==0){
            count++;
            return ;
        }
        else{
        for(int i=0;i<5;i++){
            if(prev_char<=i)
                counting(n-1,i,count);
        }
        }
    }
};


//dp solution 
class Solution {
public:
    int countVowelStrings(int n) {
        vector<int>dp(5,1);
        for(int i=0;i<n;i++){
            for(int j=1;j<5;j++){
                dp[j]=dp[j-1]+dp[j];
            }
        }
        return dp[4];
    }
};


//optimal solution
class Solution {
public:
    int countVowelStrings(int n) {
        int a=1,e=1,i=1,o=1,u=1;
        for(int j=2;j<=n;j++){
            a=a+e+i+o+u;
            e=e+i+o+u;
            i=i+o+u;
            o=o+u;
            u=u;
        }
        return a+e+i+o+u;
    }
};