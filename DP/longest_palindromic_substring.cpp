class Solution {
public:
    bool ispalindrome(string s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    string longestPalindrome(string s) {
        //brute force approach using function is palindrome or not
        int n=s.length();
        if(n==0)return "";
        if(n==1)return s;
        string result="";
        //we check at every index
        for(int i=0;i<n-1;i++){
            for(int j=1;j<=n-1;j++){
                if(ispalindrome(s.substr(i,j))){
                    if(result.length()<j){
                        result=s.substr(i,j);
                    }
                }
            }
        }
        return result;
    }
};