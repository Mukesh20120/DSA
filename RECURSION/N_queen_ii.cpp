class Solution {
    private:
      int cnt=0;
public:
    int totalNQueens(int n) {
        //creating leftrow,lowerleftdiagonal,upperleftdiagonal
        vector<bool>lr(n,false),lld(2*n-1,false),uld(2*n-1,false);
        countways(0,n,lr,lld,uld);
        return cnt;
    }
    void countways(int col,int n,vector<bool>&lr,vector<bool>&lld,
                  vector<bool>&uld){
        if(col==n){
            cnt++;
            return;
        }
        
        for(int row=0;row<n;row++){
            if(!lr[row] && !lld[row+col] && !uld[n-1+col-row]){
                lr[row]=true;
                lld[row+col]=true;
                uld[n-1+col-row]=true;
                countways(col+1,n,lr,lld,uld);
                lr[row]=false;
                lld[row+col]=false;
                uld[n-1+col-row]=false;
            }
        }
    }
};