class Solution {
public:
    void dfs(int i,int n,vector<vector<int>>&nums,vector<int>&visit){
        visit[i]=1;
        for(int j=0;j<n;j++){
            if(nums[i][j]==1 && visit[j]==0)
                dfs(j,n,nums,visit);
        }
    }
    
    int findCircleNum(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<int>visit(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(visit[i]==0){
                ans++;
                dfs(i,n,nums,visit);
            }
        }
        return ans;
    }
};