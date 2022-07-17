class Solution {
public:
    int evalRPN(vector<string>& t) {
        int n=t.size();
        int i=0;
        int cur=0;
        int sign=1;
        stack<int>st;
        while(i<n){
            if(t[i].length()==1 && !(isdigit(t[i][0]))){
                    int a=st.top();st.pop();
                    int b=st.top();st.pop();
                if(t[i][0]=='/')
                    st.push(b/a);
                else if(t[i][0]=='*')
                    st.push(b*a);
                else if(t[i][0]=='+')
                    st.push(b+a);
                else if(t[i][0]=='-')
                  st.push(b-a);
            }
            else if(t[i].length()==1 && isdigit(t[i][0])){
                st.push(t[i][0]-'0');
            }
            else{
                sign=1;
                int j=0;
                if(t[i][0]=='-'){
                  sign=-1;
                 j++;  
                }
                   for(;j<t[i].length();j++)
                       cur=cur*10+t[i][j]-'0';
                    st.push(sign*cur);
                    cur=0;
                    sign=1;
            }
           // cout<<st.top()<<endl;
        i++;
        }
         return st.top();           
    }
};


//optimal solution

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(string &s: tokens){
            if(s.length()>1 || isdigit(s[0]))
                st.push(stoi(s));
            else{
                int b=st.top();st.pop();
                int a=st.top();st.pop();
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