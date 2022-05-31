//giving TLE 

class Solution {
public:
   void generate(string temp,int n, unordered_map<string,int>&mp){
        if(n==0){
            mp[temp]=0;
            return;
        }
       generate(temp+"0",n-1,mp);
       generate(temp+"1",n-1,mp);
    }
    
    bool hasAllCodes(string s, int k) {
      //step 1 generate all the substring of binary code
                int n=s.length();
             if(n<k)
                 return false;
        unordered_map<string,int>mp;
        //we have three method to make first string of k size 00000
        //1 using for loop and concatination
        //2 using str.append(int,char);
        //3 directly initilize str(int,char);
       //vector<string>str;
         generate("",k,mp);
        // for(auto &it: mp)
        //     cout<<it.first<<" "<<it.second<<endl;
        
        
        //step 2 we use two loop to find all the substring in map
        for(int i=0;i<=n-k;i++){
            string temp=s.substr(i,k);
           // cout<<temp<<" "<<i<<" "<<i+k<<endl;
            if(mp.find(temp)!=mp.end())
                mp[temp]++;
          //  temp="";
        }
      for(auto &it: mp){
          if(it.second==0)
              return false;
      }  
        return true;
      
    }
};


//modified above code 
//as we know the total binary number generate is 2 pow k
//so we add all the substring in the map and check the size if size of the map
//equal to the total no. of binary code can made the return true
//other wise return false

class Solution {
public:

    bool hasAllCodes(string s, int k) {
                int n=s.length();
             if(n<k)
                 return false;
        unordered_map<string,int>mp;   
        //step 2 we use two loop to find all the substring in map
        for(int i=0;i<=n-k;i++){
            string temp=s.substr(i,k);
            if(mp.find(temp)==mp.end())
                mp[temp]++;
        }
        int p=1<<k;
     if(mp.size()==p)
         return true;
        
        return false;
      
    }
};


//above code little bit modification
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        //checking the lenght of string is greater than k or not
        if(s.length()<k)
            return false;
        //store the all unique substring
        unordered_set<string>unst;
        
        for(int i=0;i<=s.length()-k;i++){
            unst.insert(s.substr(i,k));
        }
        
        return unst.size()==pow(2,k);
    }
};