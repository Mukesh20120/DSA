//brute approach using max heap as a min heap by inserting -ve value

//problem in this solution we are filling the priority queue we taking space 
// size of p 2d vector we can reduce it to k size by pop extra distance
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
       priority_queue<pair<int,int>>q;
        //push distance and the index
        for(int i=0;i<p.size();i++){
            int x=p[i][0]*p[i][0];
            int y=p[i][1]*p[i][1];
            int d=x+y;
            q.push({-d,i});
        }
        vector<vector<int>>ans;
        while(!q.empty() && k--){
            ans.push_back(p[q.top().second]);
            q.pop();
        }
        return ans;
    }
};

//optimal than above code using k space in priority queue
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
       priority_queue<pair<int,int>>q;
        //push distance and the index
        for(int i=0;i<p.size();i++){
            int x=p[i][0]*p[i][0];
            int y=p[i][1]*p[i][1];
            int d=x+y;
            if(q.size()<k)
             q.push({d,i});
            else if(d<q.top().first){
                q.pop();
                q.push({d,i});
            }
        }
        vector<vector<int>>ans;
        while(!q.empty()){
            ans.push_back(p[q.top().second]);
            q.pop();
        }
        return ans;
    }
};

//other solution o(nlogn) tc using sort the array and return kth element
class Solution {
public:
   
//     static bool cmp(vector<int>&a,vector<int>&b){
//         int ax=a[0]*a[0];
//         int ay=a[1]*a[1];
//         int bx=b[0]*b[0];
//         int by=b[1]*b[1];
        
//         return (ax+ay)<(bx+by);
//     }
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        //sort the point vector in ascencing order store k element
        //other way to declare the comparator
        sort(p.begin(),p.end(),[&](vector<int>&a,vector<int>&b){
        int ax=a[0]*a[0];
        int ay=a[1]*a[1];
        int bx=b[0]*b[0];
        int by=b[1]*b[1];
        
        return (ax+ay)<(bx+by);
    });
       // vector<vector<int>>ans(p.begin(),p.begin()+k);
        return vector<vector<int>>(p.begin(),p.begin()+k);
    }
};

//other two solution o(n) tc quick sort algo used solution page on leetcode