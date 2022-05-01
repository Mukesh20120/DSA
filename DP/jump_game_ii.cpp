//recursion solution gives tle 
//exploring all the path we can 
class Solution {
public:
    int helper(vector<int>&nums,int cur,int dest){
        //base case check if we reach the last index of the vector or not
        if(cur>=dest)
            return 0; //if we reach at the end we will return 0
        //temp variable to count the minimum steps
        int temp=INT_MAX;
        //exploring the jump from 1 to the position we can jump
        for(int i=1;i<=nums[cur];i++){
            temp=min(temp,1+helper(nums,cur+i,dest)); //passing in the function
        }
        return temp;
    }
    
    int jump(vector<int>& nums) {
        //here we will try to expolore the all possible path we can search
        //using recursion passing vector,index and the destination where we want to go
       return helper(nums,0,nums.size()-1);
    }
};


//using memoization above code 
class Solution {
public:
    int helper(vector<int>&nums,int cur,int dest,vector<int>&dp){
        //base case check if we reach the last index of the vector or not
        if(cur>=dest)
            return 0; //if we reach at the end we will return 0
        if(dp[cur]!=-1)
            return dp[cur];
        //temp variable to count the minimum steps
        int temp=1e8;
        //exploring the jump from 1 to the position we can jump
        for(int i=1;i<=nums[cur];i++){
            temp=min(temp,1+helper(nums,cur+i,dest,dp)); //passing in the function
        }
        dp[cur]=temp;
        return temp;
    }
    
    int jump(vector<int>& nums) {
        //here we will try to expolore the all possible path we can search
        //using recursion passing vector,index and the destination where we want to go
        //memoization of the above code
        int n=nums.size();
        vector<int>dp(n+1,-1);
       return helper(nums,0,nums.size()-1,dp);
    }
};

//optimal solutin using just three variable to find answer
class Solution {
public:
    int jump(vector<int>& nums) {
        //our three variable 
        int curmax=0,jumps=0,curreach=0;
        //we run a loop from 0 to size-1 to find the jumps
        for(int i=0;i<nums.size()-1;i++){
            //if we find the curmax greater then i+nums[i] we will update our curmax
            if(i+nums[i]>curmax)
                curmax=i+nums[i];
            //second case we will check if i==curreach
            if(i==curreach){
                jumps++;
                curreach=curmax;
            }
        }
        return jumps;
    }
};