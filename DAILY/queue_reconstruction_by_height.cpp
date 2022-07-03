class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]<b[0])return false;
        if(a[0]==b[0])return a[1]<b[1];
        return true;
    }
   
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
 //steps first sort the vector according to their height if height is same then sort according to k
        int n=people.size();
        vector<vector<int>>ans;
        sort(people.begin(),people.end(),cmp);
        
      for(int i=0;i<n;i++)
          ans.insert(ans.begin()+people[i][1],people[i]);
     
        return ans;
    }
};