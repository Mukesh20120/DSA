class Solution {
public:
    
    string frequencySort(string s) {
        //we need to store the characte and its frequency
        unordered_map<char,int>map;
        for(char &c: s)
            map[c]++;
        //we need a priority queue to get max every time
        priority_queue<pair<int,char>>q;
        for(auto &it: map)
            q.push({it.second,it.first});
        string ans="";
        while(!q.empty()){
            pair<int,char>t=q.top();
            string temp(t.first,t.second);
            q.pop();
            ans+=temp;
        }
        return ans;
    }
};