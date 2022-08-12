class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       int len=intervals.size();
        vector<vector<int>>res;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<len;i++){
            int a=intervals[i][0];
            int b=intervals[i][1];
            for(int j=i+1;j<len;j++){
                int c=intervals[j][0];
                int d=intervals[j][1];
                if(b>=c){
                    b=max(b,d);
                    i=j;
                }
            }
            res.push_back({a,b});
        }
        return res;
    }
};