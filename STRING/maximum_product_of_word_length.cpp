//solve using store the frequency of the words

class Solution {
public:
    bool NotMatch(string s,string p){
        //we masking the bits
        int A[26]={0},B[26]={0};
        //filling the vector
        for(char &c: s)
            A[c-'a']++;
        for(char &d: p)
            B[d-'a']++;
        
        //now we just have to match the both array
        for(int i=0;i<26;i++){
            if(A[i] && B[i])
                return false;
        }
        return true;
    }
    
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(NotMatch(words[i],words[j])){
                    int len=words[i].length()*words[j].length();
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};



//optimized more the above code we store the bit making of perticular words 
//store in the array and use two loop find the match the which have no match

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        //array for store the bit masking of the words
        int nums[n];
        //variable to make bit masking
        int cur;
        for(int i=0;i<n;i++){
            cur=0;
            for(int j=0;j<words[i].length();j++){
                int nm=words[i][j]-'a';
                cur=cur | 1<<nm;
            }
            nums[i]=cur;
        }
        
        int ans=0;
        //as we have fill the array with bit masking now 
        //we just have to check the previous and cur value doing 
        // and operation 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                //a&b if all bit is different it gave 0
                if((nums[i]&nums[j])==0){
                    int res=words[i].length()*words[j].length();
                    ans=max(ans,res);
                }
            }
        }
        
        return ans;
    }
};