class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        //brute force approach we can use two loop for that
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    ans[i]=j-i;
                    break;
                }
            }
        }
        return ans;
    }
};


//optimal approach using stack
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int cur=0;cur<n;cur++){
            int temp=nums[cur];
            while(!st.empty() && nums[st.top()]<temp){
                int prev=st.top();
                st.pop();
                ans[prev]=cur-prev;
            }
            st.push(cur);
        }
        return ans;
    }
};