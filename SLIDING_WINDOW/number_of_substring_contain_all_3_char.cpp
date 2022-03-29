class Solution {
public:
    int numberOfSubstrings(string s) {
        //as we know the string consist of only abc
        vector<int>visit(3,0); //marking all the 3 different character
        int i=0,n=s.length(),st=0;
        int ans=0;
        for(i=0;i<n;i++){
            visit[s[i]-'a']++; //marking count of that character
            while(visit[0] && visit[1] && visit[2]){  //if any index all 3 pre.
                ans+=n-i;  
                visit[s[st]-'a']--;
                st++;
            }
        }
        return ans;
    }
};