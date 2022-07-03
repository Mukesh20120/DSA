class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int b=0,e=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(maxi<nums[i]){
                maxi=nums[i];
                b=i;
            }
          if(mini>nums[i]){
                mini=nums[i];
                e=i;
            }
        }
       if(b>e)swap(b,e);
        //now we know b is smaller and e is greater
        //3 case 
        //first case is e taking element from start
        //second case is taking element from end int end=n-1-b;
        //third case is b+(n-e-1)
        //take minimum from them
        int first=e+1;
        int second=n-b;
        int third=(b+1)+(n-e);
       
       return min(first,min(second,third)); 
    }
};