class Solution {
public:
    string removeDuplicates(string s) {
       //here we can use stack to solve this problem
        stack<char>st;
        //now we insert the character in stack and check if previous is equal to the cur we pop it
        for(int i=0;i<s.length();i++){
            if(!st.empty() && st.top()==s[i])
               st.pop(); 
            else
                st.push(s[i]);
        }
        //now our stack have no duplicate we just have to add all the character in our answer
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};