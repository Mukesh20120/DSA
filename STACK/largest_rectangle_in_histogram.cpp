class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n),right(n);   
        stack<int>st;
        //left array filling 
        for(int i=0;i<n;i++){
            //we have two case 1 if we not find anything and stack is empty
            if(st.empty()){
                left[0]=0;
                st.push(i);
            }
            else{
                //traverse until we not get less of than current element
                while(!st.empty() && heights[st.top()]>=heights[i])
                    st.pop();
                //now as two case can be happen stack is empty or we found the less value
                left[i]=st.empty()?0:st.top()+1;
                //then we push the current index
                st.push(i);
            }
        }
        //as we filled the left array now we need to empty the stack so we can use it for right array
        while(!st.empty())
            st.pop();
        //filling the right array same as above in left
        for(int i=n-1;i>=0;i--){
            //two case
            if(st.empty()){
                right[i]=n-1;
                st.push(i);
            }
            else{
                //traverse back
                while(!st.empty() && heights[st.top()]>=heights[i])
                    st.pop();
                //now one thing can happen from above two condition
                right[i]=st.empty()?n-1:st.top()-1;
                st.push(i);
            }
        }
        int ans=-1;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(right[i]-left[i]+1));
        }
        return ans;
    }
};