class SubrectangleQueries {
    vector<vector<int>>temp;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        temp=rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int n) {
        for(int r=row1;r<=row2;r++){
            for(int c=col1;c<=col2;c++){
                temp[r][c]=n;
            }
        }
    }
    
    int getValue(int row, int col) {
        return temp[row][col];
    }
};


//other solution using extra space to store original and space to store the queries

class SubrectangleQueries {
    private:
     vector<vector<int>>temp,orig;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        orig=rectangle;
        //we let two vector 
        //we will check the range and if it is not in rang return original rectangle stored value
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        temp.push_back({row1,col1,row2,col2,newValue});
    }
    
    int getValue(int row, int col) {
        //we need to check if the given row and col is in the range
        
        //there is a reson we checkingrom back b/c assume if the same range given again to replace with different element
        for(int i=temp.size()-1;i>=0;i--){
            if(temp[i][0]<=row && temp[i][1]<=col && temp[i][2]>=row && temp[i][3]>=col)
                return temp[i][4];
        }
        return orig[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */