class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        //coordinate are
        int x=rStart,y=cStart;
        //total element are
        int sz=rows*cols;
        //store answer in 2d vector
        vector<vector<int>>ans;
        //step variable increase every time as we move left etc
        int step=1;
        //n variable to count the elements have filled in answer vector
        int n=0;
        //loop run up to n<size means  0 to size-1
        while(n<sz){
            //we fill leftone of matrix
            for(int i=0;i<step;i++){
                //boundary case
                if(x>=0 && x<rows && y>=0 && y<cols){
                    ans.push_back({x,y}); //push the coordinate in our answer
                    n++;// increasing the size of element
                }
                y++;//we move to next 
            }
            //we move to down side
             for(int i=0;i<step;i++){
                //boundary case
                if(x>=0 && x<rows && y>=0 && y<cols){
                    ans.push_back({x,y}); //push the coordinate in our answer
                    n++;// increasing the size of element
                }
                x++;//we move to next 
            }
            //now we have to go right to left 
            step++;
             for(int i=0;i<step;i++){
                //boundary case
                if(x>=0 && x<rows && y>=0 && y<cols){
                    ans.push_back({x,y}); //push the coordinate in our answer
                    n++;// increasing the size of element
                }
                y--;//we move to next 
            }
            //now we have to move up 
             for(int i=0;i<step;i++){
                //boundary case
                if(x>=0 && x<rows && y>=0 && y<cols){
                    ans.push_back({x,y}); //push the coordinate in our answer
                    n++;// increasing the size of element
                }
                x--;//we move to next 
            }
            //now we have to move left 1 step ahead 
            step++;
        }
        return ans;
    }
};