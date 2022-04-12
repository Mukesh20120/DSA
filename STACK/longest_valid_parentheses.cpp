//solve using two stack

class Solution {
public:
    int longestValidParentheses(string s) {
        //solve using two stack
        stack<int>st; //store the index
        stack<char>ch; //store the ( 
        st.push(-1);
        int ans=0;
        for(int i=0;i<s.length();i++){
            //two condition 1 when open bracket ( encounter
            if(s[i]=='('){
                //when we encounter open bracket we add it to ch stack and  its index
                st.push(i);
                ch.push(s[i]);
            }
            else{
                //here we have two case also
                if(!ch.empty() && ch.top()=='('){
                    ch.pop();
                    st.pop();
                    ans=max(ans,i-st.top());
                }
                else
                    st.push(i);
            }
        }
        return ans;
    }
};



//using one stack 
class Solution {
public:
    int longestValidParentheses(string s) {
        //solve using two stack
        stack<int>st; //store the index
        st.push(-1);
        int ans=0;
        for(int i=0;i<s.length();i++){
            //two condition 1 when open bracket ( encounter
            if(s[i]=='(')
                st.push(i);
            else{
                //here we have two case also
                st.pop();
                if(!st.empty())
                    ans=max(ans,i-st.top());
                else
                    st.push(i);
            }
        }
        return ans;
    }
};


//optimal solution using o(n) time complexity and o(1) space complexity
class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0,close=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            //increasing open or close 
            if(s[i]=='(')
                open++;
            else
                close++;
            if(open==close)
                ans=max(ans,open+close);
            else if(close > open)
                open=close=0;
        }
        open=close=0;
        for(int i=s.length()-1;i>=0;i--){
              //increasing open or close 
            if(s[i]=='(')
                open++;
            else
                close++;
            if(open==close)
                ans=max(ans,open+close);
            else if(close < open)
                open=close=0;
        }
        return ans;
    }
};