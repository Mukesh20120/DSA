class Solution {
public:
    int fun(string s,string t,int i,int j){
        
        if(i<0)return j+1;
        if(j<0)return i+1;
        //choice we have condition when all the character are equal
        if(s[i]==t[j]) //when the character match then we required 0 operation
            return 0+fun(s,t,i-1,j-1); 
        //now we have three condition insertion,deletion,replace
        int a=fun(s,t,i-1,j);//deletion we delete char now move ahead to check next
        int b=fun(s,t,i,j-1);//insertion new element added and j move ahead
        int c=fun(s,t,i-1,j-1);//we replace the char then we move both ahead
        
        //we take which one give minimum value
        return  1+min(a,min(b,c));
    }
    
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        return fun(word1,word2,n-1,m-1);
    }
};