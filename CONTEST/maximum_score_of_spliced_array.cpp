class Solution {
public:
    //maxsubarray we can find using kadane algorithm
    int maxsubarray(vector<int>&nums){
        int sum=0;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(ans<sum)
                ans=sum;
            if(sum<0)
                sum=0;
        }
        return ans;
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        //make two array difference of each other element
        int n=nums1.size(); //both vector have same length
        vector<int>first(n,0),second(n,0);
        int sum1=0,sum2=0;//for nums1 and nums2 respectively
        for(int i=0;i<n;i++){
            sum1+=nums1[i];
            sum2+=nums2[i];
            first[i]=nums2[i]-nums1[i];
            second[i]=nums1[i]-nums2[i];
        }
        int res1=maxsubarray(first)+sum1;
        int res2=maxsubarray(second)+sum2;
        
        return max(res1,res2);
    }
};

//we don't need extra space to calculate the difference same concept can be modified as

//optimized above code

class Solution {
public:
    int helper(vector<int>&a,vector<int>&b){
        int sum=accumulate(a.begin(),a.end(),0);
        //kadane to find max subarry
       int res=0,s=0;
    for(int i=0;i<a.size();i++){
        int d=b[i]-a[i];
        s+=d;
        if(res<s)
            res=s;
        if(s<0)
            s=0;
    }
        return sum+res;
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
      return max(helper(nums1,nums2),helper(nums2,nums1));
    }
};