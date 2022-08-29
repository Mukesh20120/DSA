class Solution {
public:
    bool check(string &s,int p,string &t){
        for(int i=0;i<s.length();i++){
            if(t[i+p]!='?' && t[i+p]!=s[i])
                return false;
        }
        return true;
    }
    int replace(string &s,int p,string &t,int cnt){
        for(int i=0;i<s.length();i++){
            if(t[i+p]!='?'){
                t[i+p]='?';
                cnt++;
            }
        }
        return cnt;
    }
    vector<int> movesToStamp(string stamp, string target) {
        string t=target;
        string s=stamp;
        vector<bool>visit(t.length(),false);
        vector<int>ans;
        int cnt=0;
        bool flag;
        while(cnt!=t.length()){
            flag=false;
            for(int i=0;i<=t.length()-s.length();i++){
                if(!visit[i] && check(s,i,t)){
                    cnt=replace(s,i,t,cnt);
                    ans.push_back(i);
                    flag=true;
                    visit[i]=true;
                }
                if(cnt==t.length())
                    break;
            }
            if(!flag)
                 return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};