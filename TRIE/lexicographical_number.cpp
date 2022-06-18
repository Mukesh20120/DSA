//lets create a class of trie data structure
class trie{
private:
    trie *list[27]; //same as declare trie
    int weight;    //maintain the index of trie
public:
    trie(){  //constructor
        memset(list,0,sizeof(list));
        weight=0;
    }
    //simple insert function at every index we updating weight
   void insert(string word,int w){
       trie *cur=this;
       for(char &c: word){
           if(cur->list[c-'a']==NULL)
               cur->list[c-'a']=new trie();
           cur=cur->list[c-'a'];
           cur->weight=w;
       }
   } 
    
    //checking we able to find the weight or not of suffix+"{"+preffix
    int startwith(string s){
         trie *cur=this;
       for(char &c: s){
           if(cur->list[c-'a']==NULL)
               return -1;
           cur=cur->list[c-'a'];
       }
        return cur->weight;
    } 
};

class WordFilter {
public:
    trie root;//making object of class
    WordFilter(vector<string>& words) {
        int idx=0; //index
        for(string &s: words){
            root.insert(s,idx); //inserting the word
            string temp="{"+s;  //inserting the last element to every
            for(int i=s.length()-1;i>=0;i--){
                string newword=s[i]+temp;
                temp=newword;
                root.insert(newword,idx);
            }
            idx++;
        }
    }
    
    int f(string prefix, string suffix) {
        string newword=suffix+"{"+prefix;
        return root.startwith(newword);
    }
};

