class Solution {
public:
    vector<string> wordSubsets(vector<string>& w1, vector<string>& w2) {
       int prev[26];
        int w2hash[26]={0};
        for(string s: w2){
            memset(prev,0,sizeof(prev));
            for(char c: s){
                 prev[c-'a']++;   
            }
            for(int i=0;i<26;i++){
                if(prev[i]>w2hash[i])
                    w2hash[i]=prev[i];
            }
        }
        
        vector<string>ans;
        int temp[26];
        for(string s: w1){
            memset(temp,0,sizeof(temp));
            for(char c: s)
              temp[c-'a']++;
            bool flag=true;
           for(int i=0;i<26;i++){
                if(w2hash[i]>temp[i]){
                    flag=false;
                    break;
                }
            }
            if(flag)
                ans.push_back(s); 
        }
       return ans; 
    }
};