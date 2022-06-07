class Solution {
public:
    string reverse(string t){
        int n=t.length()-1;
        int i=0;
        while(i<n){
            swap(t[i++],t[n--]);
        }
        return t;
    }
    long long smallestNumber(long long num) {
        //there is two test case we need to remember
        //first we get positive and othe when get negative
        if(num==0)
            return 0;
        
        //check for negative number
        bool neg=false;
        //store the answer
        long long ans;
        //checking negative
        if(num<0)
            neg=true;
        //converting given number to string
        string t=to_string(num);
        //sorting in ascending order
        sort(t.begin(),t.end());
        
        //if it is negative then we just need to reverse the 
        //sorted string and convert to long long and return -ans
        if(neg){
            t=reverse(t);
             ans=-stoll(t);
        }
        //if it is positive then no leading 0 so we need to find the
        //non zero number and swap with first character and return ans
        else{
           int j=0;
            while(t[j]=='0'){
                j++;
            }
            swap(t[0],t[j]);
            ans=stoll(t);
        }
        return ans;
    }
};