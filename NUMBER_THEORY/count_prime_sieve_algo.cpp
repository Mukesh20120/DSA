class Solution {
public:
    int countPrimes(int n) {
        //sieves algorithm
        //make array to store prime of not marking all prime
        if(n<=1)return 0;
        vector<bool>nums(n,true);
       //starting from index 2 b/c 0 and 1 not count in prime
        for(int i=2;i*i<n;i++){
            int j=2; //for multiplication
        if(nums[i])
            while(i*j<n){ //marking false all the multiple of i
                nums[i*j]=false;
                j++;
            }
        }
 //traverse through array if found true then it is our prime count in 
        int ans=0;
        for(int i=2;i<n;i++){
          if(nums[i])
              ans++;
        }
        
        return ans;
    }
};