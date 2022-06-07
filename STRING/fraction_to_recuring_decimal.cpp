class Solution {
public:
    string fractionToDecimal(int no, int de) {
        //we first divide it and check if it divisible
       string ans;
        long n=no;
        long d=de;
        if(n<0 && d>0 || n>0 && d<0){
            ans="-";
            if(n<0)
              n*=-1;
            if(d<0)
                d*=-1;
        }
        long q=n/d;
        long r=n%d;
        ans+=to_string(q);
        unordered_map<long,int>mp;
        //now we have two case when remender 0 then return ans
        if(r){
            ans+=(".");
            while(r){
                if(mp.find(r)!=mp.end()){
                    int pos=mp[r];
                    ans.insert(pos,"(");
                    ans+=")";
                    break;
                }
                else{
                    mp[r]=ans.length();
                     r*=10;
                     q=r/d;
                     r=r%d;
                    ans+=to_string(q);
                }
            }
        }
        return ans;
    }
};