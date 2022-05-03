//brute force approach giving tle
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=n,r=0;
        //using two loop finding the every possible subarray
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    l=min(l,i);
                    r=max(r,j);
                }
            }
        }
        return r-l<0?0:r-l+1;
    }
};


//beter approach using other vector to store the vector and sort it
// time complexity nlogn space complexity n
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       vector<int>num=nums;
        sort(num.begin(),num.end());
        int n=nums.size();
        //inilized with max and min
        int l=n,r=0;
        for(int i=0;i<n;i++){
            if(num[i]!=nums[i]){
                l=min(l,i);
                r=max(r,i);
            }
        }
        return r-l<0?0:r-l+1;
    }
};

//solve using stack 
//time complexity o(n) and we using stack then space complexity is o(n)

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //using stack
        int n=nums.size();
        stack<int>st;
        int left=n-1;
        //loop from 0 to n-1
        for(int i=0;i<n;){
            //here we have 3 case 
            //1st case when stack is empty
            if(st.empty())
                st.push(i++); //we will push index only
            else if(nums[st.top()]>nums[i])
                left=min(left,st.top()),st.pop();
            else
                st.push(i++);
        }
        //we find the left same we do for right
        while(!st.empty()){
            st.pop();
        }
        
        
        int right=0;
        for(int i=n-1;i>=0;){
            //here we have 3 case 
            //1st case when stack is empty
            if(st.empty())
                st.push(i--); //we will push index only
            else if(nums[st.top()]<nums[i])
                right=max(right,st.top()),st.pop();
            else
                st.push(i--);
        }
        if(left>=right)
            return 0;
        return right-left+1;
    }
};