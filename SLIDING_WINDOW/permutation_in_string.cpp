class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //length of the string
        int n=s1.length(),m=s2.length();
        //making a hash map initilized with 0
        vector<int>hash(26,0);
        //checking the length of s1 and s2
        if(n>m)return false;
        //initilize the frequency of the s1 string
        for(int i=0;i<n;i++)
            hash[s1[i]-'a']++;
        //running a loop sliding window
        for(int i=0;i<m;i++){
            //we will decrease each time until
            hash[s2[i]-'a']--;
            //checking for sliding window
            if(i-n>=0)
                hash[s2[i-n]-'a']++;
            //checking each time all zero or not in hash map
            if(allzero(hash))
                return true;
        }
        return false;
    }
    //checking for all zero in hash map
    bool allzero(vector<int>&hash){
        for(int i=0;i<26;i++){
            if(hash[i]!=0)
                return false;
        }
        return true;
    }
};