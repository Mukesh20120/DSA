class Solution {
public:
    void matchstr(string s,unordered_map<string,bool>&mp,queue<string>&q){
        for(int i=0;i<s.length();i++){
            char c=s[i];
            for(int j=0;j<26;j++){
                s[i]=j+'a';
                if(mp.find(s)!=mp.end() && mp[s]==false){
                    cout<<s<<" ";
                    mp[s]=true;
                    q.push(s);
                }
            }
            s[i]=c;
        }
    }
    bool comparestr(string &s,string &x){
        if(s.length()!=x.length())return false;
        for(int i=0;i<s.length();i++){
            if(s[i]!=x[i])
                return false;
        }
        return true;
    }
    int ladderLength(string bw, string ew, vector<string>& wl) {
        //checking the endword is present in vector or not if not then it is 
        //not possible to make ladder
        if(find(wl.begin(),wl.end(),ew)==wl.end())return 0;
       
        //hashmap to marking visited or not
        unordered_map<string,bool>mp;
        //filling the map with the all string and false;
       for(string s: wl)
           mp[s]=false;
       
        //queue data structure to BFS traversal
        queue<string>q;
        
        //first string will be 
        mp[bw]=true;
        q.push(bw);
        
         //ans to count the length as above we push the being string 
        int length=1;
        
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string s=q.front();
                q.pop();
             
                //check the word is end word or not it endword return length
                if(comparestr(s,ew))
                    return length;
                matchstr(s,mp,q);
            }
            length++;
        }
        return 0;
    }
};