// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        //we make two variable
        while(true){
            //row goes up to 6
            int row=(rand7()-1)*7;
            //col goes upto 7
            int col=rand7();
            //now we add both
            int add=row+col;
            if(add<=40){
                return 1+(add-1)%10;
            }
        }
    }
};