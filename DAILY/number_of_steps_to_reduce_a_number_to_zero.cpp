class Solution {
public:
    int numberOfSteps(int n) {
        int step=0;
        while(n){
            if(n&1)
                n-=1;
            else
              n/=2;
            step++;
        }
        return step;
    }
};