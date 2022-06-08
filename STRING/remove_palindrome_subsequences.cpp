class Solution {
public:
    bool ispalindrome(string s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++,j--;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if(ispalindrome(s)){
            return 1;
        }
        return 2;
    }
};