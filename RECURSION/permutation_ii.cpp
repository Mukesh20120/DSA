class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        compute(0,res,temp,temp.size());
        return res;
    }
    void compute(int i,vector<vector<int>>&res,vector<int>temp,int n){
        //base case
        if(i==n){
            res.push_back(temp);
            return;
        }
        //we will try all the element by swaping it
        for(int j=i;j<n;j++){
            if(j!=i && temp[i]==temp[j])
                continue;
            //other wise swap and passing into the function
            swap(temp[i],temp[j]);
            compute(i+1,res,temp,n);
        }
    }
};