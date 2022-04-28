class Solution {
public:
    vector<vector<string>> partition(string s) {
        //2d vector store the all the palindrom
        vector<vector<string>>res;
        //1d vector it is temproary vector
        vector<string>temp;
        //pasing these into function we check from 0 index
        helper(0,s,temp,res);
        
        return res;
    }
    //recursion and backtracking
    void helper(int index,string s,vector<string>&temp,vector<vector<string>>&res){
        //base case
        //if we are a last index then we push our temperoary answer in result
        if(index==s.length()){
            res.push_back(temp);
            return;
        };
        
        //we run a loop for every index
        for(int i=index;i<s.length();i++){
            //pasing in function to check palindrom
            if(ispalindrom(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                helper(i+1,s,temp,res);
                temp.pop_back();
            }
        }
    }
    bool ispalindrom(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
};