class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int n=pushed.size();
        int m=popped.size();
        int j=0;
    for(int i=0;i<n;i++){
        st.push(pushed[i]);
        while(!st.empty() && j<m && st.top()==popped[j]){
            st.pop();
            j++;
        }
    }
    
        return j==m;
    }
};

//2 method more optimal space complexity o(1)
//but we are manipulating the data 
class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        int j=0,i=0;
        for(int &a: pu){
            pu[i]=a;
            i++;
            while(i>0 && pu[i-1]==po[j]){
                i--;
                j++;
            }
        }
        return i==0;
    }
};