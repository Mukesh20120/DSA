class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //make a hash map of size 255 for all alphabet and character
        vector<int>hash(256,-1);
        //size of string n
        int n=s.length();
        //make right ,left and len ans
        int right,left,len;
        right=left=len=0;
        while(right<n){
            //the character is already present
            if(hash[s[right]]!=-1){
                left=max(left,hash[s[right]]+1);
            }
            //updating the hash map
            hash[s[right]]=right;
            //taking max len
            len=max(right-left+1,len);
            right++;
        }
        return len;
    }
};