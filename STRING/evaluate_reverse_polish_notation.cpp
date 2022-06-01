class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string &s: tokens){
            //checking the length of string and the first character of string
            if(s.length()>1 || isdigit(s[0]))
                st.push(stoi(s));
            else{
                int b=st.top(); st.pop();
                int a=st.top(); st.pop();
                switch(s[0]){
                    case '+':
                        a+=b;
                        break;
                    case '-':
                        a-=b;
                        break;
                    case '*':
                        a*=b;
                        break;
                    case '/':
                        a/=b;
                        break;
                }
                st.push(a);
            }
        }
        return st.top();
    }
};