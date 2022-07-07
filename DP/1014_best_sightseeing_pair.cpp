//brute force solution 
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        //brute force solution
        int ans=0;
        int n=values.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int sum=values[i]+values[j]+i-j;
                ans=max(sum,ans);
            }
        }
        return ans;
    }
};


//optimal solution 

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int res=0,cur=values[0];
        for(int i=1;i<values.size();i++){
            res=max(res,cur+values[i]-i);
            cur=max(cur,values[i]+i);
        }
        return res;
    }
};