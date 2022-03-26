//this approach giving tle
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
      int n=nums.size();  //size of given array
        vector<int>ope(n); //making vector to store the xor of nums
        ope[n-1]=nums[0];  //last element same as first element of the nums
        for(int i=1;i<n;i++){
           ope[n-i-1]=ope[n-i]^nums[i];  //filling the ope vector with xor 
        }
        vector<int>ans;
        int m=1<<maximumBit; //k value goes upto
        for(int i=0;i<n;i++){
            int k=0;
            int maxi=0;
            int maxixor=0;
            while(k<m){
               int temp=ope[i]^k; //calculating xor with each value of k
                if(maxixor<temp){
                    maxixor=temp;
                    maxi=k; //taking maximum xor giving value of k
                }
                k++;
            }
            ans.push_back(maxi);//store in ans 
        }
        return ans;
    }
};

//optimal approach 
//xor of maximum will be 2^maximumbit-1 ans all nums ans so on
//tricky question
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int sxor=0;
        int n=nums.size();
        vector<int>ans(n);
        for(int it: nums)
            sxor^=it;
        ans[0]=sxor^=(1<<maximumBit)-1;
        for(int i=1;i<n;i++)
            ans[i]=sxor^=nums[n-i];
        
        return ans;
    }
};