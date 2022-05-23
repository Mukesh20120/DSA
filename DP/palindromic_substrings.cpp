//using two loop check every substing 

class Solution {
public:
    int countSubstrings(string s) {
        //brute force approach using loop
        int n=s.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispalindrom(s,i,j))
                    cnt++;
            }
        }
        return cnt;
    }
    bool ispalindrom(string s,int i,int j){
        while(i<=j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
};

//other approach using Expand around center n^2 approach using no extra space

class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=ispalindrome(s,i,i); //we taking single character
            ans+=ispalindrome(s,i,i+1);// we taking two character as centre
        }
        return ans;
    }
    int ispalindrome(string s,int i,int j){
        int cnt=0;
        while(i>=0 && j<s.length() && s[i--]==s[j++])
            cnt++;
        
        return cnt;
    }
};