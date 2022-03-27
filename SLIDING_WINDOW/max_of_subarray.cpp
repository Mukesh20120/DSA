class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
       vector<int>ans;
       for(int i=0;i<=n-k;i++){
            int temp=0;
          for(int j=i;j<i+k;j++){
              if(temp<arr[j])
                temp=arr[j];
          }
          ans.push_back(temp);
       }
       return ans;
    }
};