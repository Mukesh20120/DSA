class Solution {
public:
    bool match(string a,string b){
        unordered_map<char,char>atob,btoa;
        for(int i=0;i<a.length();i++){
            if(atob.find(a[i])==atob.end())atob[a[i]]=b[i];
            if(btoa.find(b[i])==btoa.end())btoa[b[i]]=a[i];
            if(atob[a[i]]!=b[i] || btoa[b[i]]!=a[i])
                return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& w, string p) {
        //using two unordered hash map
        vector<string>ans;
        for(auto word: w){
            if(match(word,p))
                ans.push_back(word);
        }
        return ans;
    }
};


class Solution {
public:
    bool match(string a,string b){
        unordered_map<char,char>hash;
        
        for(int i=0;i<a.length();i++){
            if(hash.find(a[i])==hash.end())
                hash[a[i]]=b[i];
            if(hash[a[i]]!=b[i])
                return false;
        }

     vector<bool>visited(26,false);
        for(auto p:hash){
            if(visited[p.second-'a'])
                return false;
            visited[p.second-'a']=true;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& w, string p) {
        //using two unordered hash map
        vector<string>ans;
        for(auto word: w){
            if(match(word,p))
                ans.push_back(word);
        }
        return ans;
    }
};