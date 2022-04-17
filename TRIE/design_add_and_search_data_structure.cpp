class WordDictionary {
public:
    struct node{
        node *list[26];
        bool flag=false;
    };
    node *root;
    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node *cur=root;
        for(int i=0;i<word.length();i++){
            if(cur->list[word[i]-'a']==NULL)
                cur->list[word[i]-'a']=new node();
            cur=cur->list[word[i]-'a'];
        }
        cur->flag=true;
    }
    
    bool Trie_search(string s,node *cur,int pos)
    {    //if pos is the last then we just need to check for flag is true or not
        if(pos==s.length())
            return cur->flag;
        //now we have two case one in which we get . and other we get word
        if(s[pos]!='.'){
            cur=cur->list[s[pos]-'a'];
            return cur && Trie_search(s,cur,pos+1);
        }
        //other if condition is not enter then we s[i]='.'
        for(int i=0;i<26;i++){
            if(cur->list[i] && Trie_search(s,cur->list[i],pos+1))
                return true;
        }
        return false;
    }
    
    bool search(string word) {
                     //string,root,size of string,index
      return Trie_search(word,root,0);
    }
   
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */