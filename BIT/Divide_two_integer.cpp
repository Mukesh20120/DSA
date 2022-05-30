class Solution {
public:
    long helper(long dividend,long divisor){
        if(dividend<divisor)
            return 0;
        long sum=divisor;
        long count=1;
        while((sum<<1)<=dividend){
            sum=sum<<1;
            count+=count;
        }
        return count+helper(dividend-sum,divisor);
    }
    
    int divide(int dividend, int divisor) {
       //now we just need to check all the test cases
        long count=0;
        //checking negative answer
        bool neg=false;
        //checking any one of then negative or not
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0))
            neg=true;
        
        long div=abs((long)dividend);
        long dis=abs((long)divisor);
      
        count=helper(div,dis);
        
        if(count>INT_MAX){
            if(neg)
                return INT_MIN;
            else
                return INT_MAX;
        }
        else
            if(neg)
                return -count;
      
        return count;
    }
};