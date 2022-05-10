class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        //vector for returning the ans
        vector<vector<int>>ans;
        //temp vector to store the element 
        vector<int>temp;
        //making a function 
        solve(1,n,k,ans,temp);
        return ans;
    }
    void solve(int i,int sum,int k,vector<vector<int>>&ans,vector<int>&temp){
        //base case
        if(sum==0 && temp.size()==k){
            ans.push_back(temp);
            return;
        }
        //we try every test case from 1 to 9
        for(int j=i;j<=9;j++){
            temp.push_back(j);
            solve(j+1,sum-j,k,ans,temp);
            temp.pop_back();
        }
    }
};