class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
       
        int maxi=0;
        for(int i=1;i<points.size();i++){
            int x1=points[i-1][0];
            int x=points[i][0];
            maxi=max(maxi,x-x1);
        }
        return maxi;
    }
};