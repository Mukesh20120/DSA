//simple approach using bit

class Solution {
public:
    int hammingWeight(uint32_t n) {
        //simple approach
        int cnt=0;
        for(int i=0;i<32;i++){
            if((n>>i)&1){
                cnt++;
            }
        }
        return cnt;
    }
};

//optimal solution 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        //we will do and operation with n and n-1
        int cnt=0;
        while(n){
            n=n&(n-1);
            cnt++;
        }
        return cnt;
    }
};