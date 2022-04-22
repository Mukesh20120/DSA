class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //brute force solution using two loop
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};


//better approach we just need to traverse through left and down

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //better approach is we move left and bottom
        int i=0,j=matrix[0].size()-1;
        //as we moving from left and down we just need to traverse
        //the inside the boundary of the matrix
        while(i<matrix.size() && j>=0){
            //if the position is found we return true;
            if(matrix[i][j]==target)
                return true;
            //we have two case we move left or down
            if(matrix[i][j]>target) //all the value down are larger 
                j--;
            else //all the value on left are smaller
                i++;
        }
        return false;
    }
};