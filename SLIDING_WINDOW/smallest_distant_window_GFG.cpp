//brute force approach but time complexity O(length*length*256)
class Solution{
    public:
    bool matching(bool temp[],bool hash[]){
        for(int i=0;i<256;i++)
           if(temp[i]!=hash[i])
             return false;
     return true;
    }
    
    int findSubString(string str)
    {
       //making a hash function
       int l=str.length();
       bool hash[256]={0};
       //filling the hash function
       for(char &c: str)
         hash[c]=true;
         
         //now we check every sub string using two loop
         bool temp[256]={false};
         int ans=l;
         for(int i=0;i<l;i++){
             memset(temp,0,sizeof(temp));
             for(int j=i;j<l;j++){
                 temp[str[j]]=true;
                 if(matching(temp,hash)){
                     ans=min(ans,j-i+1);
                 }
             }
         }
         return ans;
    }
};


//optimal solution

class Solution{
    public:
    bool matching(bool temp[],bool hash[]){
        for(int i=0;i<256;i++)
           if(temp[i]!=hash[i])
             return false;
     return true;
    }
    
    int findSubString(string str)
    {
       //making a hash function
       int l=str.length();
       bool hash[256]={0};
       //filling the hash function
       for(char &c: str)
         hash[c]=true;
         
         //now we check every sub string using two loop
         bool temp[256]={false};
         int ans=l;
         for(int i=0;i<l;i++){
             memset(temp,0,sizeof(temp));
             for(int j=i;j<l;j++){
                 temp[str[j]]=true;
                 if(matching(temp,hash)){
                     ans=min(ans,j-i+1);
                 }
             }
         }
         return ans;
    }
};