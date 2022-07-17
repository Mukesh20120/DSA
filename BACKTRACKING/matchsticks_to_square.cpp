//recursion + backtracking using visited array
//similare question 698
class Solution {
    private:
    int visited[16];
    int subset;
public:
    bool helper(vector<int>&nums,int cur,int n,int k){
        if(k==1)return true;
        if(cur==subset){
            return helper(nums,0,nums.size(),k-1);
        }
       for(int i=n-1;i>=0;i--){
           if(visited[i] || cur+nums[i]>subset)
               continue;
           visited[i]=1;
           cur+=nums[i];
           if(helper(nums,cur,i+1,k))
               return true;
           visited[i]=0;
           cur-=nums[i];
       }
        
     return false;
    }
    bool makesquare(vector<int>& nums) {
         int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%4!=0)return false;
        memset(visited,0,sizeof(visited));
        subset=sum/4;
        int n=nums.size();
        return helper(nums,0,n,4);
    }
};