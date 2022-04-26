class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<int>nums(m,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                nums[j]=matrix[i][j]=='1'?nums[j]+1:0;
            }
            int temp=lon_his(nums,m);
            if(ans<temp)
                ans=temp;
        }
        return ans;
    }
    int lon_his(vector<int>&nums,int m){
        vector<int>left(m),right(m);
        stack<int>st;
        //left filling 
        for(int i=0;i<m;i++){
            //two case
            if(st.empty()){
                left[i]=0;
                st.push(i);
            }
            else{
                while(!st.empty() && nums[st.top()]>=nums[i])
                    st.pop();
                //now if stack is empty we fill with 0
                left[i]=st.empty()?0:st.top()+1;
                st.push(i);
            }
        }
        //now we empty the stack
        while(!st.empty())
            st.pop();
        
        //filling the right vector
        for(int i=m-1;i>=0;i--){
             //two case
            if(st.empty()){
                right[i]=m-1;
                st.push(i);
            }
            else{
                while(!st.empty() && nums[st.top()]>=nums[i])
                    st.pop();
                //now if stack is empty we fill with 0
                right[i]=st.empty()?m-1:st.top()-1;
                st.push(i);
            }
        }
        //taking the maximum area we can get fomr the array
        int ans=0;
        for(int i=0;i<m;i++)
            ans=max(ans,nums[i]*(right[i]-left[i]+1));
     
        return ans;
    }
};