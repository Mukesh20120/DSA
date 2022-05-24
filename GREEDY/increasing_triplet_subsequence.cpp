//brute force approach

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]<nums[j] && nums[j]<nums[k])
                        return true;
                }
            }
        }
        return false;
    }
};

//better approach but using extra space to store the low and high element from particular index

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //better solution using mini and high vector
        int n=nums.size();
        int low[n],high[n];
        //filling the low array with low element from index
        low[0]=nums[0];
        for(int i=1;i<n;i++)
          low[i]=min(low[i-1],nums[i]);
        //filling the high array from the index
        high[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            high[i]=max(high[i+1],nums[i]);
        
        
        // for(int i=0;i<n;i++)
        //     cout<<low[i]<<" "<<high[i]<<endl;
        //now we need to check 
        for(int i=0;i<n;i++){
            if(low[i]<nums[i] && high[i]>nums[i])
                return true;
        }
        return false;
    }
};

//optimal solution using three variable
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int f=INT_MAX,s=INT_MAX;
        for(int &i: nums){
            if(i<=f)
                f=i;
            else if(i<=s)
                s=i;
            else
                return true;
        }
        return false;
    }
};