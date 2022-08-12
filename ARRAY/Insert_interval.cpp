//brute force approach after inserting the quesiton boil down to merge interval

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& I, vector<int>& NI) {
        //brute force approach 
        //step 1 insert the inverval in intervals array
        vector<vector<int>>ans;
        I.push_back(NI);
        //step 2 sort the interval array
        sort(I.begin(),I.end());
        //step 3 now quesiton boil down to merge interval
        int n=I.size();
        for(int i=0;i<n;i++){
            int a=I[i][0];
            int b=I[i][1];
            for(int j=i+1;j<n;j++){
                int c=I[j][0];
                int d=I[j][1];
                if(b>=c){
                    b=max(b,d);
                    i=j;
                }
            }
            ans.push_back({a,b});
        }
        return ans;
    }
};

//optimal solution 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        int i=0;
        int n=intervals.size();
        //until we not get overlap
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        //merge or not merge
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0]=min(intervals[i][0],newInterval[0]);
            newInterval[1]=max(intervals[i][1],newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);
        //last part 
        while(i<n && intervals[i][0]>newInterval[1]){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};