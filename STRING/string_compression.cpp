class Solution {
public:
    int compress(vector<char>& chars) {
    
        int i=0,j;
        int ind=0;
        int n=chars.size();
        while(i<n){
           j=i;
            while(i<n && chars[i]==chars[j])i++;
           
            chars[ind++]=chars[j];
            if(i-j>1){
                string cnt=to_string(i-j);
                for(char c: cnt){
                    chars[ind++]=c;
                }
            }
        }
       return ind;
    }
};