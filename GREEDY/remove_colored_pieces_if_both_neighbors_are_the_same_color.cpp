class Solution {
public:
    bool winnerOfGame(string c) {
        //as from observation we have to count the number of triplet of int the color string of a and b
        int Atrip=0;
        int Btrip=0;
        //we traverse through colors
        for(int i=2;i<c.size();i++){
            if(c[i]=='A' && c[i-1]=='A' && c[i-2]=='A')
                Atrip++;
            else if(c[i]=='B' && c[i-1]=='B' && c[i-2]=='B')
                Btrip++;
        }
        if(Atrip<=Btrip)
            return false;
        return true;
    }
};

//optimal solution 

class Solution {
public:
    bool winnerOfGame(string c) {
        int alice=0,bob=0;
        int cnt=0;
        int n=c.size();
        int i=0;
        while(i<n){
            cnt=0;
            while(i<n && c[i]=='A'){
                cnt++;
                i++;
            }
            alice+=max(0,cnt-2);
            cnt=0;
            while(i<n && c[i]=='B'){
                cnt++;
                i++;
            }
            bob+=max(0,cnt-2);
        }
        return alice>bob;
    }
};