class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int w=words[0].length();//length of the word
        int n=s.length();
           vector<int>ans;
        if(n<(w*words.size()))
            return ans;
     
        unordered_map<string,int>mp,hash; //word and its frequency
        
        for(string &i: words)
             mp[i]++;
        //we will traverse through the string and check every index
        for(int i=0;i<=n-w*words.size();i++){
          string key=s.substr(i,w);
            hash=mp;
            if(mp.find(key)!=mp.end()){
                int j=i;
                while(j<n && hash.size()){
                    string temp=s.substr(j,w);
                    if(hash.find(temp)!=hash.end()){
                       if(--hash[temp]==0)
                           hash.erase(temp);
                    }
                    else
                        break;
                    j+=w;
                }
                if(hash.size()==0)
                    ans.push_back(i);
                hash=mp;
            }
        }
        return ans;
    }
};