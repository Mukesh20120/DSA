class Solution {
public:
    bool backspaceCompare(string s, string t) {
        //it can be solve using two stack 
        //we will pop out when we encounter with #
        stack<char>st1,st2;
        //filling the stack
        int i=0,j=0,n=s.length(),m=t.length();
        while(i<n || j<m){
            if(i<n){
                if(s[i]!='#')
                   st1.push(s[i]);
                else
                    if(!st1.empty())
                        st1.pop(); 
            i++;
            }
             if(j<m){
                if(t[j]!='#')
                   st2.push(t[j]);
                else
                    if(!st2.empty())
                        st2.pop();    
            j++;
            }
        }
        //this code is for debugging the code 
        // while(!st1.empty()){
        //     cout<<st1.top()<<" ";
        //     st1.pop();
        // }
        // cout<<endl;
        // while(!st2.empty()){
        //     cout<<st2.top()<<" ";
        //     st2.pop();
        // }
        
         if(st1.size()!=st2.size())
            return false;
        while(!st1.empty() || !st2.empty()){
            if(st1.top()!=st2.top()){
                return false;
            }
            st1.pop();
            st2.pop();
        }
        return true;
    }
};


//optimal solution using string builder function 
//we build string same concept like stack
class Solution {
public:
    string build(string s){
        string a="";
        int k=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='#')
                k++;
            else if(k==0)
                a.push_back(s[i]);
            else
                k--;
        }
        return a;
    }
    bool backspaceCompare(string s, string t) {
         //we build a string making string builder 
        return build(s)==build(t);
    }
};