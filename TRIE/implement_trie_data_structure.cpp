class Trie {
public:
    struct Node{
        Node *list[26];
        bool flag=false;
    };
    Node *root;
    
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node *temp=root;
        for(int i=0;i<word.length();i++){
            if(!temp->list[word[i]-'a']){
                temp->list[word[i]-'a']=new Node();
            }
            temp=temp->list[word[i]-'a'];
        }
        temp->flag=true;
    }
    
    bool search(string word) {
        Node *node=root;
        for(int i=0;i<word.length();i++){
            if(!node->list[word[i]-'a']){
                return false;
            }
            node=node->list[word[i]-'a'];
        }
        return node->flag;
    }
    
    bool startsWith(string word) {
          Node *node=root;
        for(int i=0;i<word.length();i++){
            if(!node->list[word[i]-'a']){
                return false;
            }
            node=node->list[word[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */