class Solution {
    private:
    int mod=1e9+7;
    unordered_map<string,long>mp;
public:
    int countVowelPermutation(int n) {
        long total=0;
        char ch[]={'a','e','i','o','u'};
        for(char c: ch){
            total=(total+helper(n-1,c))%mod;
        }
        return (int)total;
    }
    long helper(int remain,char prev){
        if(remain==0)
            return 1;
        string key=""+to_string(remain)+prev;
        if(mp.find(key)!=mp.end())return mp[key];
        long total=0;
        switch(prev){
            case 'a':
                total=helper(remain-1,'e')%mod;
                break;
            case 'e':
                total=(helper(remain-1,'a')+helper(remain-1,'i'))%mod;
                break;
            case 'i':
                total=(helper(remain-1,'a')+helper(remain-1,'e')+helper(remain-1,'o')+helper(remain-1,'u'))%mod;
                break;
            case 'o':
               total=helper(remain-1,'i')+helper(remain-1,'u')%mod;
                break;
            case 'u':
                total=helper(remain-1,'a')%mod;
                break;
        }
        mp[key]=total;
        return total;
    }
};


//optimal solution 

class Solution {
public:
    int countVowelPermutation(int n) {
        long long int a,e,i,o,u,mod=1e9+7;
        a=e=i=o=u=1;
        for(int k=2;k<=n;k++){
            long long int ta=a,te=e,ti=i,to=o,tu=u;
            a=te;
            e=ta+ti;
            i=ta+te+to+tu;
            o=ti+tu;
            u=ta;
            
            a%=mod;
            e%=mod;
            i%=mod;
            o%=mod;
            u%=mod;
        }
        return (a+e+i+o+u)%mod;
    }
};