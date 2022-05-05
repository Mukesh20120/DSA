class Solution {
public:
    string simplifyPath(string path) {
        //optimal solution solve using stack
        stack<string>st;
        string ans;
        //we iterate through whole loop
        for(int i=0;i<path.size();i++){
            //if our first element is '/'
            if(path[i]=='/')
                continue;
           //we make a temp string and take all the character b/w of / and /
            string temp;
            while(i<path.size() && path[i]!='/'){
                temp+=path[i];
                i++;
            }
            //now we have three case
            if(temp==".")//we will ignore it
                continue;
            else if(temp==".."){
                //we have to go back to parents empty the stack from top
                if(!st.empty())
                    st.pop();
            }
            else
                st.push(temp);
        }
        //as we have fill our stack now we just need to print in ans
        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();
        }
      //now here we have two case if ans is still empty then we return /
        if(ans.size()==0)
            return "/";
        
        return ans;
    }
};