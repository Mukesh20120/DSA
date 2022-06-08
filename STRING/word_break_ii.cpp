class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>set;
        vector<string>ans;
        for(auto a: wordDict)
            set.insert(a);
        string curr="";
        solve(0,s,curr,set,ans);
        return ans;
    }
    void solve(int ind,string s,string cur,unordered_set<string>&set,vector<string>&ans){
        if(ind==s.length()){
            cur.pop_back();
            ans.push_back(cur);
        }
        string str="";
        for(int i=ind;i<s.length();i++){
            str.push_back(s[i]);
            if(set.count(str))
                solve(i+1,s,cur+str+" ",set,ans);
        }
    }
};