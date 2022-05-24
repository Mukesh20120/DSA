//reference from leetcode solution page

//brute force approach 

class Solution {
public:
    int longestSubstring(string s, int k) {
        //we will generate all the substring and check if it is
        //valid or not if valid we store max of it
        int masking[26]={0};
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            memset(masking,0,sizeof(masking));
            for(int j=i;j<n;j++){
                masking[s[j]-'a']++;
                if(isvalid(k,masking))
                    ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
    bool isvalid(int k,int mapping[26]){
        //we don't need start and end we just need to check in masking
        int cntletter=0,cntatleastk=0;
        for(int i=0;i<26;i++){
            if(mapping[i]>0)cntletter++;
            if(mapping[i]>=k)cntatleastk++;
        }
        return cntletter==cntatleastk;
    }
};


//other approach using divide and con.
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.length();
        return helper(s,0,n,k);
    }
    int helper(string S,int s,int e,int k){
        if(e<k)
            return 0;
        //make a countarray
        int count[26]={0};
        //iterate through substring
        for(int i=s;i<e;i++)
            count[S[i]-'a']++;
           for(int mid=s;mid<e;mid++){
               if(count[S[mid]-'a']>=k)continue;
               int midnext=mid+1;
               while(midnext<e && count[S[midnext]-'a']<k)midnext++;
               return max(helper(S,s,mid,k),helper(S,midnext,e,k));
        }
        return e-s;
    }
};