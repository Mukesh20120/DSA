class Solution {
public:
    int getSum(int a, int b) {
        //solution of neet code
        //if we take xor of a and b we get ans but 
        //not able to store the carry for store the carry
        //we take and of a and b left shift by q 
        //and do xor again
        int sum=a;
        while(b!=0){
           sum=a^b;
           b=unsigned(a&b)<<1;
           a=sum;
        }
        return a;
    }
};