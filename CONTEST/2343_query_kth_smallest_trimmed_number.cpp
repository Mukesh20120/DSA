class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        vector<pair<string,int>>temp(nums.size());
        vector<int>ans;
        int n=nums[0].length();
        for(int i=0;i<q.size();i++){
            int s=q[i][0];
            int t=q[i][1];
            for(int j=0;j<nums.size();j++){
                temp[j]={nums[j].substr(n-t),j};
            }
            sort(temp.begin(),temp.end());
           ans.push_back(temp[s-1].second);
        }
    return ans;
    }
};