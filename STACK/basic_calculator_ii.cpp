class Solution {
public:
    int calculate(string s) {
        int n=s.length();
        //stack
        stack<int>st;
        //we required two variable
        int curnum=0;
        char opera='+';
        for(int i=0;i<n;i++){
            char cur=s[i];
            //checking if it is digit or not
            if(isdigit(cur))
                curnum=(curnum*10)+(cur-'0');
            if(!isdigit(cur) && !iswspace(cur) || i==n-1){
                if(opera=='-')
                    st.push(-curnum);
                else if(opera=='+')
                    st.push(curnum);
                else if(opera=='*'){
                    int a=st.top();
                    st.pop();
                    st.push(a*curnum);
                }
                else if(opera=='/'){
                     int b=st.top();
                    st.pop();
                    st.push(b/curnum);
                }
                opera=cur;
                curnum=0;
            }
        }
         int res=0;
            while(!st.empty()){
                int a=st.top();
                res+=a;
                st.pop();
            }
        
        return res;
    }
};