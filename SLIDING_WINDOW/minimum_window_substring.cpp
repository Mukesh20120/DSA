class Solution {
public:
    string minWindow(string s, string t) {
        //make a hashtable of t string
        unordered_map<char,int>mp; //store character and its frequency
        //filling the unordered map with character and its frequency
        for(char c: t)
            mp[c]++;
        //count variable to check the lenght 
        int count=0,low=0,min_length=INT_MAX,min_start=0;
        //sliding window
        for(int high=0;high<s.length();high++){
            if(mp[s[high]]>0)count++;
            mp[s[high]]--;
            if(count==t.length()){
                //now we will move the low pointer
                while(low<high && mp[s[low]]<0){
                    mp[s[low]]++;
                    low++;
                }
                if(min_length>high-low){
                    //update min length
                    min_length=high-low+1;
                    min_start=low;
                }
                mp[s[low++]]++;
                count--;
            }
        }
        return min_length==INT_MAX?"":s.substr(min_start,min_length);
    }
};