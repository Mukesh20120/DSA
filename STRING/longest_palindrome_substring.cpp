//sloving using palindrome partion but giving TLE

class Solution {
public:
    string longestPalindrome(string s) {
        //let try to do with palindrom partition solution
        vector<vector<string>>res;
        vector<string>temp;
        helper(0,s,temp,res);
        
        string ans="";
        int maxi=0;
        for(int i=0;i<res.size();i++){
            for(int j=0;j<res[i].size();j++){
                if(maxi<res[i][j].length()){
                    maxi=res[i][j].length();
                    ans=res[i][j];
                }
            }
        }
        return ans;
    }
    void helper(int index,string s,vector<string>&temp,vector<vector<string>>&res){
        //base case
        if(index==s.length()){
            res.push_back(temp);
            return;
        }
        for(int i=index;i<s.length();i++){
            if(ispalindrome(s,index,i)){
               temp.push_back(s.substr(index,i-index+1));
                helper(i+1,s,temp,res);
                temp.pop_back();
            }
        }
    }
    bool ispalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
};


//finding palindrome from centre

class Solution {
public:
    string longestPalindrome(string s) {
        //we will find the length 
        //we calculate from center of the string
        int len=0;
        int start=0;//this is for the taking substring form the string
        for(int i=0;i<s.length();i++){
            int len1=helper(s,i,i+1); //checking for the baab
            int len2=helper(s,i,i);//checking for the string baabaab
            //we will take maximum
            if(len<max(len1,len2)){
                len=max(len1,len2);
                start=i-(len-1)/2;
            }
        }
        return s.substr(start,len);
    }
    int helper(string s,int i,int j){
        //boundary case and then check for palindrome
        while(i>=0 && j<s.length() && s[i]==s[j]){
            i--;
            j++;
        }
        return j-i-1;
    }
};