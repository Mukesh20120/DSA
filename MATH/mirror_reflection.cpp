class Solution {
public:
    int mirrorReflection(int p, int q) {
        int ext=q;
        int rel=p;
        while(ext%2==0 && rel%2==0){
            ext/=2;
            rel/=2;
        }
        if(ext%2==0 && rel%2==1)
            return 0;
        else if(ext%2 && rel%2==0)
            return 2;
       else if(ext%2==1 && rel%2==1)
           return 1;
        
        return -1;
    }
};