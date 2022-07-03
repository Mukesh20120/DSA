class Solution {
public:
    bool checkdistinct(string s,int ml){
        int arr[26]={0};
        for(char &c: s)
            arr[c-'a']++;
        int unique=0;
        for(int i=0;i<26;i++)
            if(arr[i]!=0)
                unique++;
       if(unique<=ml)
           return true;
    return false;
    }
    
    int maxFreq(string s, int ml, int mn, int mx) {
        //required a map to store the string and its frequency
        unordered_map<string,int>hash;
          int ans=0;
        //run a loop from mn to mx and take every possible substring and check it character frequecny
        //if it if true we add into map else discard it
        for(int i=mn;i<=mx;i++){
            for(int j=0;j<=s.length()-i;j++){
                //substr(position,length)
                string sub=s.substr(j,i);
                if(checkdistinct(sub,ml)){
                     hash[sub]++;
                    ans=max(ans,hash[sub]);
                }
                  
            }
        }
      
//         for(auto &it: hash)
//             if(it.second>ans)
//                 ans=it.second;
      
        return ans;
    }
};