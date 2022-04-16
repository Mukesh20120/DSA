class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //brute force approach 
        //we find first occarance by linear search and then then continuation
        vector<int>ans={-1,-1};
        int n=nums.size();
        if(n==0)return ans;
        //finding first occarance
        int i,j;
        for(i=0;i<n;i++)
            if(nums[i]==target)
                break;
        if(i==n){
            return ans;
        }
        ans[0]=i;
        //last occarance
        for(j=i;j<n;j++)
            if(nums[j]!=target)
                break;
        ans[1]=--j;
        
        return ans;
    }
};



class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //optimal approach using binary search
        int low=0,n=nums.size(),high=n-1;
        vector<int>ans={-1,-1};
        //first occerance check left side
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans[0]=mid;
                high=mid-1;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
         //last occerance check left side
        //reset low and  high again
        low=0;
        high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                ans[1]=mid;
                low=mid+1;
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return ans;
    }
};


//making one function on above code we repeat the code we can make a function
//don't need to repeat the code

class Solution {
public:
    void search(vector<int>&ans,vector<int>&nums,int target,bool flag){
       int low=0,n=nums.size(),high=n-1;
       while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                if(flag){
                ans[0]=mid;
                high=mid-1;
                }
                else{
                ans[1]=mid;
                low=mid+1;
                }
            }
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        //optimal approach using binary search
        vector<int>ans={-1,-1};
       search(ans,nums,target,true);
       search(ans,nums,target,false);

        return ans;
    }
};