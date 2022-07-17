class Solution {
public:
    int calculate(string s) {
        int sign=1;
        int ans=0;
        long long cur=0;
        int n=s.length();
        int i=0;
        stack<int>st;
        while(i<n){
            //when first char is digit
            if(isdigit(s[i])){
                //we take a digit untile we get sign
                while(i<n && isdigit(s[i])){
                    cur=cur*10 + s[i]-'0';
                    i++;
                }
                ans+=sign*cur;
                cur=0;
                sign=1;
                i--;
            }else if(s[i]=='+')
                sign=1;
            else if(s[i]=='-')
                sign=-1;
            else if(s[i]=='('){
                //we push the ans and then sign in stack
                st.push(ans);
                st.push(sign);
                //reset the all
                cur=0;
                sign=1;
                ans=0;
            }
            else if(s[i]==')'){
                int prevsign=st.top();st.pop();
                ans=prevsign*ans;
                int prevans=st.top();st.pop();
                ans+=prevans;
            }
            i++;
        }
        return ans;
    }
};