//resursion solution+memoization 
//reference from aditya verma dp series

class Solution {
    private:
      unordered_map<string,bool>map;
public:
    bool isScramble(string s1, string s2) {
        if(s1.compare(s2)==0)
            return true;
        if(s1.length()<=1)
            return false;
        //making key
        string key=s1;
        key.push_back(' ');
        key.append(s2);
        if(map.find(key)!=map.end())
          return map[key];
        
        int n=s1.length();
        bool flag=false;
        for(int i=1;i<n;i++){
            bool case1=(isScramble(s1.substr(0,i),s2.substr(n-i,i)) 
                        && isScramble(s1.substr(i,n-i),s2.substr(0,n-i)));
            bool case2=(isScramble(s1.substr(0,i),s2.substr(0,i)) 
                        && isScramble(s1.substr(i,n-i),s2.substr(i,n-i)));
            if(case1 || case2){
                flag=true;
                break;
            }
        }
        return map[key]=flag;
    }
};