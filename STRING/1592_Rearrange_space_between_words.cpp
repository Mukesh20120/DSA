class Solution {
public:
    string reorderSpaces(string text) {
        vector<string>words;
        int space=0;
        string word;
        for(int i=0;i<text.size();i++){
            if(text[i]==' '){
                space++;
                if(!word.empty()){
                    words.push_back(word);
                    word="";
                }
            }
            else
                word+=text[i];
        }
        //in last check word is empty
        if(!word.empty())
            words.push_back(word);
        
        //now if words have only one word then
        if(words.size()==1)
            return words[0]+string(space,' ');
        
        int gap=space/(words.size()-1);
        int extraspace=space%(words.size()-1);
        string ans;
        for(auto w: words)
            ans+=w+string(gap,' ');
        
        return ans.substr(0,ans.size()-gap)+string(extraspace,' ');
    }
};