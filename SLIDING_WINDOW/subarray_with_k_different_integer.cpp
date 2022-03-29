class Solution {
public:
    int atmost(vector<int>&A,int k){
        if(k==0)
            return 0; 
        int n=A.size();
        int total=0;
        int diff=0;
        int j=0;
        int visit[20002]={0};
        for(int i=0;i<n;i++){
            if(visit[A[i]]==0)
                diff++;
          visit[A[i]]++;
          while(j<n && j<i && diff>k){
              visit[A[j]]--;
              if(visit[A[j]]==0)
                  diff--;
              j++;
          } 
          total+=i-j+1; 
        }
        return total;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};