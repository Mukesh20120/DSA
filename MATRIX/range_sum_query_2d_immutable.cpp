//brute force approach

class NumMatrix {
    private:
    vector<vector<int>>temp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        temp=matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1;i<=row2;i++){
            for(int j=col1;j<=col2;j++){
                sum+=temp[i][j];
            }
        }
        return sum;
    }
};

//optimal solution
class NumMatrix {
    private:
      vector<vector<int>>temp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        temp=matrix;
        //adding column vise in temp
        for(int i=0;i<temp.size();i++){
            for(int j=1;j<temp[i].size();j++){
                temp[i][j]+=temp[i][j-1];
            }
        }
        
        //adding row wise in temp
         for(int i=1;i<temp.size();i++){
            for(int j=0;j<temp[i].size();j++){
                temp[i][j]+=temp[i-1][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total=temp[row2][col2];
        int extra=row1!=0?temp[row1-1][col2]:0;
        extra+=col1!=0?temp[row2][col1-1]:0;
        if(row1 && col1)
        extra-=temp[row1-1][col1-1];
        
        return total-extra;
    }
};



