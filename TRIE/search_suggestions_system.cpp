class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& pro, string sw) {
        //sort the given string vector
        sort(pro.begin(),pro.end());
        //we return answer
        vector<vector<string>>ans;
        //traverse through the given string one character at a time
        string cur="";
        for(char &c: sw){
            //add every character one by one
            cur+=c;
            //temp vector to store string
            vector<string>temp;
            auto it=lower_bound(pro.begin(),pro.end(),cur); //it gave the pointer to that word or above
            //just traverse through that point and add next 3 string in temp vector if have 
            for(int i=0;i<3 && it+i!=pro.end();i++){
                string &s=*(it+i);
                if(s.find(cur))break; //match means further is other string with different prifix
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//other solution time and space complexity is greater but the way question is solve is using trie data structure

//making trie data structure
class trie{
    public:
        trie *list[26];
        bool flag;
    trie(){
       memset(list,0,sizeof(list));
        flag=false;
    }
};
class Solution {
public:
    void Insert(trie *node,vector<string>&pro){
        int n=pro.size();
        for(int i=0;i<n;i++){
            trie *cur=node;
            string s=pro[i];
            for(int j=0;j<s.length();j++){
                if(cur->list[s[j]-'a']==NULL)
                    cur->list[s[j]-'a']=new trie();
               cur=cur->list[s[j]-'a'];
            }
            cur->flag=true;
        }
    }
    
    void dfs(trie *cur,string word,vector<string>&result){
        //we required only 3 size
        if(result.size()==3)return;
        //check it is a word or not
        if(cur->flag)
            result.push_back(word);
        //running dfs
        for(char c='a';c<='z';c++){
          if(cur->list[c-'a']){
              word+=c;
              dfs(cur->list[c-'a'],word,result);
              word.pop_back();
          }
        }
    }
    
    
    vector<string> getword(trie *root,string pre){
        //move the pointer to the end of the pre string
        trie *cur=root;
        vector<string>result;
        for(int i=0;i<pre.length();i++){
            if(cur->list[pre[i]-'a']==NULL)
                return result;
           cur=cur->list[pre[i]-'a'];
        }
        //filling the result vector with search words
        dfs(cur,pre,result);
        
        return result;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string sw) {
        trie *root=new trie();
        //now let insert all the element in trie
        Insert(root,products);
        //we store answer in 
        vector<vector<string>>ans;
        
        string prefix;
        for(char &c: sw){
            prefix+=c;
            ans.push_back(getword(root,prefix));
        }
        return ans;
    }
};