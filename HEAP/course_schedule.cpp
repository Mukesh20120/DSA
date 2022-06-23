class Solution {
public:
    int scheduleCourse(vector<vector<int>>& c) {
        //referacne from algo made easy
        sort(c.begin(),c.end(),[&](vector<int>&a,vector<int>&b){return a[1]<b[1];});
        priority_queue<int>q;
        int ans=0;
        for(int i=0;i<c.size();i++){
            q.push(c[i][0]);
            ans+=c[i][0];
            if(ans>c[i][1]){
                   ans-=q.top();
                q.pop();
            
            }
             
        }
        return q.size();
    }
};