class Solution {
public:
    int trailingZeroes(int n) {
        //we just need to calculate the total no. of count in 5 in n
      int cnt=0;
        for(int i=5;n/i;i*=5){
            cnt+=n/i;
        }
        return cnt;
    }
};