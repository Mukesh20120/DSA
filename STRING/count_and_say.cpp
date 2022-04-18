class Solution {
public:
    string countAndSay(int n) {
        return count(n,"1"); //our function
    }
    string count(int n,string s){
        if(n==1)return s; //base case
        string res=""; // answer
        int j,i=0;  //index
        while(i<s.length()){
            j=i;
            while(i<s.length() && s[i]==s[j])i++;
            
            res+=to_string(i-j)+s[j]; //updating the res
        }
        return count(n-1,res);
    }
};