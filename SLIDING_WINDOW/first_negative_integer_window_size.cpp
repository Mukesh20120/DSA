// naive approach 

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    vector<long long int>ans;
    bool flag=true;
    for(int i=0;i<=N-K;i++){
        flag=true;
        for(int j=i;j<i+K;j++){
            if(A[j]<0){
                ans.push_back(A[j]);
                flag=false;
                break;
            }
        }
        if(flag)
        ans.push_back(0);
    }
    return ans;
 }

// 2 method optimal approach 



vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
       vector<long long>ans;
       int j=-1;
       for(int i=0;i<=N-K;i++){
           if(j<i){
              j=i;
           while(j<N && A[j]>0)j++;
            }//our negative index
         if(j>=i && j<i+K)
           ans.push_back(A[j]);
         else
           ans.push_back(0);
       }
       return ans;
 }