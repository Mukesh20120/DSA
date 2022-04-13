class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //assuming there is four pointer  
           //top left cornor,top left cornor,column,row
        int top=0,left=0,right=matrix[0].size()-1,bottom=matrix.size()-1;
        vector<int>temp;
        while(top<=bottom && left<=right){
            if(left>right)
                break;
            for(int i=left;i<=right;i++)
                temp.push_back(matrix[top][i]);
            top++;
            if(top>bottom)
                break;
            for(int i=top;i<=bottom;i++)
                temp.push_back(matrix[i][right]);
            right--;
            if(left>right)
                break;
            for(int i=right;i>=left;i--)
                temp.push_back(matrix[bottom][i]);
            bottom--;
            if(top>bottom)
                break;
            for(int i=bottom;i>=top;i--)
                temp.push_back(matrix[i][left]);
            left++;
        }
        return temp;
    }
};