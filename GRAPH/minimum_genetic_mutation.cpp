class Solution {
    private:
    char  a[4]={'A','C','G','T'};
public:
    bool comparestr(string s,string x){
        for(int i=0;i<8;i++){
            if(s[i]!=x[i])
                return false;
        }
        return true;
    }
    
    void matchstr(string s,unordered_map<string,bool>&mp,queue<string>&q){
        for(int i=0;i<8;i++){
            char org=s[i];
            for(int j=0;j<4;j++){
                s[i]=a[j];
                if(mp.find(s)!=mp.end() && mp[s]==false){
                    mp[s]=true;
                    q.push(s);
                }
            }
            s[i]=org;
        }
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        //hashmap for the marking visited string 
        unordered_map<string,bool>mp;
        //queue data structure for bfs traversal
        queue<string>q;
        //filling the hashmap
        for(string s: bank)
            mp[s]=false;
        int length=0;
        q.push(start);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                string s=q.front();
                q.pop();
                if(comparestr(s,end))
                    return length;
                matchstr(s,mp,q);
            }
            length++;
        }
        return -1;
    }
};