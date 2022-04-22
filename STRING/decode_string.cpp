class Solution {
public:
    string decode(string &s,int &i){
        //storing result string
        string result;
        //running loop until we find last bracket
        while(i<s.length() && s[i]!=']'){
            //we have two case first we encounter with digit
            if(isdigit(s[i])){
                //now if it is digit then we need to count the digit
                int k=0;
                while(i<s.length() && isdigit(s[i])){
                    k=k*10+s[i]-'0';
                    i++;//move to next digit
                }
                i++; //move to the next inside other bracket
                //passing same with recursion
                string r=decode(s,i);
                //now we get the string we have to add up to k times
                while(k--){
                    result+=r;
                }
                i++;
            }
            else
                result+=s[i++];
        }
        return result;
    }
    string decodeString(string s) {
        int i=0;
        return decode(s,i);
    }
};