//using set remove all substring from set
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        //brute force approach remove all the substring from the data structure
        set<string>hash;
        for(string &s: words)
            hash.insert(s);
        //algorithm we take a word and find it substring present in the set if present we remove it
        //we start from 1 because if we start with 0 whole element will be removed
        for(auto &s: hash){
            for(int i=1;i<s.length();i++){
                hash.erase(s.substr(i));//it make sub string start from 1 index ex-for time ime,me,e
            }
        }
        int ans=0;
        for(auto &s : hash){
            ans+=s.length()+1;
        }
        return ans;
    }
};


//trie solution

class trie{
    public:
    trie *list[26];
    int count;
    string s;
    trie(){
        memset(list,0,sizeof(list));
        count=0;
        s="";
    }
};
class Solution {
public:
    void Insert(trie *root,vector<string>&words){
        for(int i=0;i<words.size();i++){
            string s=words[i];
            trie *cur=root;
            for(int j=s.length()-1;j>=0;j--){
                char c=s[j];
                if(cur->list[c-'a']==NULL)
                    cur->list[c-'a']=new trie(),cur->count++;
                cur=cur->list[c-'a'];
            }
            cur->s=words[i];
        }
    }
    int givelength(trie *root){
       if(root==NULL)
            return 0;
        if(root->count==0)
            return root->s.length()+1;
        int cnt=0;
        for(int i=0;i<26;i++)
            cnt+=givelength(root->list[i]);
        return cnt;
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        trie *root=new trie();
        Insert(root,words);
      
       return givelength(root);
    }
};