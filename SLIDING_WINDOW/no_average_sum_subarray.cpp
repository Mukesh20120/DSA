class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int th) {
        int n=arr.size();
        //our loop will run up to n-1-k
        int ans=0;
        int sum=0;
        int j=0;
        //running loop upto n-k position
        for(int i=0;i<=n-k;i++){
            //running j upto size of sliding window +1
            while(j<i+k && j<n){
                sum+=arr[j];
                j++;
            }
            //remain first character
           if(i!=0)
              sum=sum-arr[i-1];
            
          //  cout<<sum<<" "<<i<<" "<<j<<" "<<endl;
            if(sum/k>=th)
                ans++;
        }
        return ans;
    }
};