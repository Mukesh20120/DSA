//naive approach using unordered map
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        return false;
       
        unordered_map<char,int>mymap;
        for(int i=0;i<s.length();i++){
            mymap[s[i]]++;
            mymap[t[i]]--;
        }
        for(auto it: mymap){
            if(it.second)
                return false;
        }
    return true;
        
        }
};


//optimal approach
class Solution {
public:
    bool isAnagram(string s, string t) {
        int mp[26]={0};
        int sz=s.length();
        int tz=t.length();
        if(sz!=tz)return false;
       for(int i=0;i<sz;i++){
           mp[s[i]-'a']++;
           mp[t[i]-'a']--;
       }
        for(int i=0;i<26;i++){
            if(mp[i]!=0)
                return false;
        }
        return true;
    }
};