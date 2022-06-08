class Solution {
    private:
    map<string,bool>mp;
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //making a set data structure to store the words
        set<string>dic;
        for(int i=0;i<wordDict.size();i++){
            dic.insert(wordDict[i]);
        }
        return solve(s,dic);
    }
    bool solve(string s,set<string>&dic){
        //base case 
        if(dic.find(s)!=dic.end())
            return true;
        if(mp.find(s)!=mp.end())
            return mp[s];
        //we will check every substring
        for(int i=0;i<s.length();i++){
            string left=s.substr(0,i);
            string right=s.substr(i);
            //now if left is present then we need to check for right
            if(dic.find(left)!=dic.end()){
                if(solve(right,dic))
                    return mp[s]=true;
            }
        }
        return mp[s]=false;
    }
};